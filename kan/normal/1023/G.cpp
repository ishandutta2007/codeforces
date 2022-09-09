/**
 * This line was copied from template
 * This is nk_ok_clear.cpp
 * 
 * @author: Nikolay Kalinin
 * @date: Fri, 10 Aug 2018 10:17:56 +0300
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;
template<typename T> T sgn(T a) { return (a < 0 ? -1 : (a > 0 ? 1 : 0)); }

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int maxn = 100005;
const int inf = 1e9;

vector<pair2<int>> gr[maxn], qs[maxn];
int sz[maxn];
int n, q;
int TIME = 0;

class tans
{
public:
    struct tpoint
    {
        int x, diff;
        
        tpoint(int x_, int diff_, int time = TIME): diff(diff_)
        {
            x = x_ + sgn(diff) * time;
        }
        
        int pos(int time = TIME) const
        {
            return x - sgn(diff) * time;
        }
        
        bool operator<(const tpoint &other) const
        {
            return pos() < other.pos();
        }
    };
    
    using ppoint = set<tpoint>::iterator;
    
    struct tseg : pair<int, ppoint> {
        bool operator<(const tseg &other) const
        {
            if (fi != other.fi) return fi < other.fi;
            return second->pos() < other.second->pos();
        }
        
        tseg(int a, const ppoint &b): pair<int, ppoint>(a, b) {}
    };
    
    set<tseg> small;
    set<tpoint> bounds;
    
    void addsegment(ppoint l, ppoint r)
    {
        int speed = sgn(r->diff) - sgn(l->diff);
        if (speed > 0)
        {
            int t = (r->pos() - l->pos() + speed - 1) / speed + TIME;
            small.insert(tseg(t, l));
        }
    }
    
    void remsegment(ppoint l, ppoint r)
    {
        int speed = sgn(r->diff) - sgn(l->diff);
        if (speed > 0)
        {
            int t = (r->pos() - l->pos() + speed - 1) / speed + TIME;
            small.erase(small.find(tseg(t, l)));
        }
    }

    tans()
    {
        bounds.insert({-inf, 0});
        bounds.insert({ inf, 0});
        addsegment(bounds.begin(), bounds.end());
    }
    
    void proceed(int time)
    {
        while (!small.empty() && small.begin()->fi <= time)
        {
            auto itl = small.begin()->se;
            auto itr = next(itl);
            int ctime = small.begin()->fi;
            remsegment(itl, itr); // removes from small
            int pos = itl->pos(ctime);
            int cdiff = itl->diff + itr->diff;
            if (itr->pos(ctime) != pos && cdiff > 0) pos--;
            auto itll = prev(itl);
            auto itrr = next(itr);
            remsegment(itll, itl);
            remsegment(itr, itrr);
            bounds.erase(itl);
            bounds.erase(itr);
            auto me = bounds.insert(itrr, tpoint(pos, cdiff, ctime));
            addsegment(itll, me);
            addsegment(me, itrr);
        }
    }
    
    int getupd(int x)
    {
        int upd = 0;
        auto itr = bounds.lower_bound(tpoint(x, 0));
        if (itr->pos() == x && itr->diff < 0) upd = max(upd, -itr->diff);
        itr = bounds.lower_bound(tpoint(x + 1, 0));
        if (itr->pos() == x + 1 && itr->diff > 0) upd = max(upd, itr->diff);
        return upd;
    }
    
    void add(int x, int t)
    {
        tpoint toadd(x, t);
        auto itr = bounds.lower_bound(toadd);
        if (toadd < *itr) // no same bound
        {
            auto itl = prev(itr);
            remsegment(itl, itr);
            auto me = bounds.insert(itr, toadd);
            addsegment(itl, me);
            addsegment(me, itr);
        } else
        {
            auto itl = prev(itr);
            auto me = itr;
            itr = next(itr);
            remsegment(itl, me);
            remsegment(me, itr);
            toadd = tpoint(x, t + me->diff);
            bounds.erase(me);
            me = bounds.insert(itr, toadd);
            addsegment(itl, me);
            addsegment(me, itr);
        }
    }
    
    vector<tpoint> getbounds()
    {
        return vector<tpoint>(all(bounds));
    }
    
    int getans()
    {
        int answer = 0;
        int cur = 0;
        for (auto t : bounds)
        {
            cur += t.diff;
            answer = max(answer, cur);
        }
        return answer;
    }
    
};

using pans = tans*;

pans go(int cur, int pr = -1)
{
    pans curans = NULL;
    for (auto e : gr[cur]) if (e.fi != pr)
    {
        TIME -= e.se * 2;
        auto t = go(e.fi, cur);
        t->proceed(TIME + (e.se - 1) * 2);
        TIME += (e.se - 1) * 2;
        t->proceed(TIME + 1);
        TIME += 1;
        if (curans == NULL) curans = t;
        else
        {
            for (auto pt : t->getbounds())
            {
                if (pt.pos() > -inf && pt.pos() < inf) curans->add(pt.pos(), pt.diff);
            }
        }
    }
    if (curans == NULL) curans = new tans();
    for (auto &curq : qs[cur])
    {
        curq.se = max(0, curq.se - curans->getupd(curq.fi));
    }
    curans->proceed(TIME + 1);
    TIME += 1;
    for (auto t : qs[cur])
    {
        curans->add(t.fi, t.se);
        curans->add(t.fi + 1, -t.se);
    }
    return curans;
}

void preprocess(int cur, int pr = -1)
{
    sz[cur] = 0;
    for (auto e : gr[cur]) if (e.fi != pr)
    {
        preprocess(e.fi, cur);
        sz[cur] += sz[e.fi];
    }
    sz[cur] += qs[cur].size();
    sort(all(gr[cur]), [&] (const pair2<int> &a, const pair2<int> &b)
                        {
                            return sz[a.fi] > sz[b.fi];
                            
                        });
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        gr[a].pb({b, c});
        gr[b].pb({a, c});
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int d, f, p;
        scanf("%d%d%d", &d, &f, &p);
        d *= 2;
        p--;
        qs[p].pb({d, f});
    }
    preprocess(0);
    auto ans = go(0);
    cout << ans->getans() << endl;
    return 0;
}