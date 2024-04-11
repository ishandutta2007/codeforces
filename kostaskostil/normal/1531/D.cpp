#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

typedef long long ll;
//#define int ll

using namespace std;
bool DBG = false;

class SegmentHandler
{
public:
    SegmentHandler(int q, string name)
    {
        nm = name;
        seg.insert({0, q+1});
    }
    void AddPoint(int x)
    {
        pts.insert(x);
        auto it = seg.upper_bound({x, 1e9});
        if (it == seg.begin())
            return;
        AddSegment(prev(it)->fi, prev(it)->se);
    }
    void RemovePoint(int x)
    {
        pts.erase(x);
        res.erase(x);
        auto it = seg.upper_bound({x, 1e9});
        if (it == seg.begin())
            return;
        AddSegment(prev(it)->fi, prev(it)->se);
    }
    void AddSegment(int l, int r)
    {
        if (l>r)
            return;
        if (DBG)
            cerr<<nm<<" add segment "<<l<<" "<<r<<"\n";
        seg.insert({l, r});
        auto it = pts.upper_bound(r);
        if (it == pts.begin())
            return;
        if (*prev(it) >= l)
            res.insert(*prev(it));
    }
    void RemoveSegment(int l, int r)
    {
        if (l>r)
            return;
        if (DBG)
            cerr<<nm<<" remove segment "<<l<<" "<<r<<"\n";
        seg.erase({l, r});

        auto it = res.upper_bound(r);
        if (it == res.begin())
            return;
        it = prev(it);

        while (true)
        {
            if (*it < l)
                break;

            if (it == res.begin())
            {
                res.erase(it);
                return;
            }

            auto it2 = it;
            it = prev(it);
            res.erase(it2);

        }
    }
    int GetLastPoint()
    {
        if (res.empty())
            return -1;
        return *prev(res.end());
    }
    void Debug(ostream& os)
    {
        for (auto pa : seg)
            os<<"{"<<pa.fi<<", "<<pa.se<<"}, ";
        return;
    }
private:
    set<pair<int, int> > seg;
    set<int> pts;
    set<int> res;
    string nm;
};

int n, q;
vector<string> comms;
map<string, set<int> > mp;
map<string, SegmentHandler> segs;

void EraseCommand(int pos)
{
    string s = comms[pos];
    if (DBG)
        cerr<<"Erasing command: "<<pos<<" "<<s<<"\n";
    mp[s].erase(pos);
    if (s == "lock")
    {
        int l = *mp["unlock"].upper_bound( *prev(mp["lock"].lower_bound(pos) ) );
        int r = *(mp["lock"].upper_bound(l));

        if ((l < pos) and (r > pos))
        {
            int lx = *mp["unlock"].upper_bound(pos);
            if (lx < r)
            for (auto& pa : segs)
            {
                pa.se.RemoveSegment(lx, r);
            }
            for (auto& pa : segs)
            {
                pa.se.RemoveSegment(l, pos);
            }
            for (auto& pa : segs)
            {
                pa.se.AddSegment(l, r);
            }
        }
    }
    else
    if (s == "unlock")
    {
        int r = *(mp["lock"].upper_bound(pos));
        int l = *mp["unlock"].upper_bound( *prev(mp["lock"].lower_bound(pos) ) );

        if (l > pos)
        for (auto& pa : segs)
        {
            pa.se.RemoveSegment(pos, r);
        }
        if (l > pos)
        for (auto& pa : segs)
        {
            pa.se.AddSegment(l, r);
        }
    }
    else
    {
        segs.at(s).RemovePoint(pos);
    }
}

void AddCommand(int pos, string s)
{
    if (DBG)
        cerr<<"Adding command: "<<pos<<" "<<s<<"\n";
    comms[pos] = s;
    if (s == "lock")
    {
        int l = *mp["unlock"].upper_bound( *prev(mp["lock"].lower_bound(pos) ) );
        int r = *(mp["lock"].upper_bound(l));

        if ((l < pos) and (r > pos))
        {
            for (auto& pa : segs)
            {
                pa.se.RemoveSegment(l, r);
            }
            for (auto& pa : segs)
                pa.se.AddSegment(l, pos);
            int lx = *mp["unlock"].upper_bound(pos);
            if (lx < r)
            for (auto& pa : segs)
            {
                pa.se.AddSegment(lx, r);
            }
        }
    }
    else
    if (s == "unlock")
    {
        int r = *(mp["lock"].upper_bound(pos));
        int l = *mp["unlock"].upper_bound( *prev(mp["lock"].lower_bound(pos) ) );

        if (l > pos)
        for (auto& pa : segs)
        {
            pa.se.RemoveSegment(l, r);
        }
        if (l > pos)
        for (auto& pa : segs)
            pa.se.AddSegment(pos, r);
    }
    else
    {
        segs.at(s).AddPoint(pos);
    }
    mp[s].insert(pos);
}

string GetResult()
{
    pair<int, string> res = {0, "blue"};
    for (auto& pa : mp)
    {
        string s = pa.fi;
        if (s == "lock" or s == "unlock")
            continue;

        pair<int, string> pax = {segs.at(s).GetLastPoint(), s};
        if (DBG)
        {
            cerr<<"Color "<<s<<" at "<<pax.fi;
            cerr<<" while segments are ";
            segs.at(s).Debug(cerr);
            cerr<<"\n";
        }
        res = max<pair<int, string> >(res, pax);
    }
    return res.se;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    mp["lock"] = { -1, n+1 };
    mp["unlock"] = { 0, n+2 };
    for (auto s : { "red" , "orange" , "yellow", "green", "blue", "indigo", "violet"} )
        segs.insert(map<string, SegmentHandler>::value_type(s, SegmentHandler(n, s)));

    comms.resize(n+2);
    for (int i=1; i<=n; i++)
    {
        cin>>comms[i];
        AddCommand(i, comms[i]);
    }

    cin>>q;
    cout<<GetResult()<<"\n";
    for (int i=1; i<=q; i++)
    {
        int v;
        string s;
        cin>>v>>s;
        EraseCommand(v);
        AddCommand(v, s);
        cout<<GetResult()<<"\n";
    }
}

/**
5
lock
unlock
red
lock
unlock
10
2 lock
3 violet
4 unlock
4 lock
5 lock
2 unlock
1 unlock
2 lock
2 unlock
3 orange
*/