#include <bits/stdc++.h>
using namespace std;

#define jjs(i, s, x) for (int i = (s); i < int(x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define ever ;;
#define foreach(x, C) for (auto& x : (C))
#define INF ((int) 1e9+10)
#define LINF ((ll) 1e16)
#define pb push_back
#define mp make_pair
#define rint(x) Read(x)
#define rlong(x) scanf("%lld", &(x))
#define nrint(x) int x; rint(x);
#define nrlong(x) long long x; rlong(x);
#define rfloat(x) scanf("%lf", &(x))

#ifndef ONLINE_JUDGE
const bool DEBUG = true;
#define Db(x...)   ({ if (DEBUG) { cout << "Debug["; DB, #x, ":", x, "]\n"; } })
template<class T> void Dbrng(T lo, T hi, string note = "", int w = 0) {
  if (DEBUG) {  
    cout << "Debug[ ";
    if (!note.empty()) cout << setw(3) << note << " : ";
    for (; lo != hi; ++lo) cout << setw(w) << *lo << " ";
    cout << "]" << endl;
  }
}
struct Debugger { template<class T> Debugger& operator ,
  (const T & v) { cout << " " << v << flush; return *this; } } DB;
#else
const bool DEBUG = false;
#define Db(x...)
#endif

const int MOD = 1000000007;
typedef long long ll;
typedef pair<int, int> pi;

const int MX = 5000000;
const int LMX = 200000;
int N, M;
pair<pi, int> videos[LMX];
pair<pi, pair<int, int> > channels[LMX];
ll ans = 0;
int idx1, idx2;
vector<int> coords;

void offer(ll value, int a, int b)
{
    if (value > ans)
    {
        ans = value;
        idx1 = a;
        idx2 = b;
    }
}

pi bestSize[MX];
pi lowestLeft[MX];
pair<ll, int> bestGain[MX];

inline int L(int x) { return x * 2 + 1; };
inline int R(int x) { return x * 2 + 2; };
inline int MID(int a, int b) { return (a + b) / 2; }

void build(int idx, int l, int r)
{
    if (l != r)
    {
        build(L(idx), l, MID(l, r));
        build(R(idx), MID(l, r) + 1, r);
    }
    bestSize[idx] = {0, -1};
    lowestLeft[idx] = {INF, INF};
    bestGain[idx] = {0, -1};
}

void put(int idx, int l, int r, pi value, int identifier)
{
    int a = coords[l];
    int b = coords[r];
    int left = value.first;
    int right = value.second;
    if (right < a || right > b)
        return;
    if (l == r)
    {
        bestSize[idx] = max(bestSize[idx], {right - left, identifier});
        lowestLeft[idx] = min(lowestLeft[idx], {left, identifier});
    }
    else
    {
        put(L(idx), l, MID(l, r), value, identifier);
        put(R(idx), MID(l, r) + 1, r, value, identifier);
        bestSize[idx] = max(bestSize[L(idx)], bestSize[R(idx)]);
        lowestLeft[idx] = min(lowestLeft[L(idx)], lowestLeft[R(idx)]);
    }
}

void put(int idx, int l, int r, pi value, ll gain, int identifier)
{
    int a = coords[l];
    int b = coords[r];
    int left = value.first;
    int right = value.second;
    if (right < a || right > b)
        return;
    if (l == r)
    {
        bestGain[idx] = max(bestGain[idx], {gain, identifier});
    }
    else
    {
        put(L(idx), l, MID(l, r), value, gain, identifier);
        put(R(idx), MID(l, r) + 1, r, value, gain, identifier);
        bestGain[idx] = max(bestGain[L(idx)], bestGain[R(idx)]);
    }
}

pi queryLeft(int idx, int l, int r, int queryL, int queryR)
{
    int a = coords[l];
    int b = coords[r];
    if (queryL <= a && queryR >= b)
        return lowestLeft[idx];
    else if (queryL > b || queryR < a)
        return {INF, INF};
    else
    {
        return min(
            queryLeft(L(idx), l, MID(l, r), queryL, queryR),
            queryLeft(R(idx), MID(l, r) + 1, r, queryL, queryR));
    }
}

pi querySize(int idx, int l, int r, int queryL, int queryR)
{
    int a = coords[l];
    int b = coords[r];
    if (queryL <= a && queryR >= b)
        return bestSize[idx];
    else if (queryL > b || queryR < a)
        return {0, -1};
    else
    {
        return max(
            querySize(L(idx), l, MID(l, r), queryL, queryR),
            querySize(R(idx), MID(l, r) + 1, r, queryL, queryR));
    }
}

pair<ll, int> queryGain(int idx, int l, int r, int queryL, int queryR)
{
    int a = coords[l];
    int b = coords[r];
    if (queryL <= a && queryR >= b)
        return bestGain[idx];
    else if (queryL > b || queryR < a)
        return {0, -1};
    else
    {
        return max(
            queryGain(L(idx), l, MID(l, r), queryL, queryR),
            queryGain(R(idx), MID(l, r) + 1, r, queryL, queryR));
    }
}

void solve(bool first = true)
{
    set<int> compress;
    ji(N)
    {
        compress.insert(videos[i].first.first);
        compress.insert(videos[i].first.second);
    }
    ji(M)
    {
        compress.insert(channels[i].first.first);
        compress.insert(channels[i].first.second);
    }
    coords.clear();
    foreach(z, compress)
        coords.pb(z);
    int S = coords.size();
    build(0, 0, S-1);
    sort(videos, videos + N);
    sort(channels, channels + M);
    int pos = N - 1;
    for (int i = M - 1; i >= 0; i--)
    {
        int left = channels[i].first.first;
        int right = channels[i].first.second;
        while (pos >= 0 && videos[pos].first.first >= left)
        {
            put(0, 0, S-1, videos[pos].first, videos[pos].second);
            Db(videos[pos].first.first, videos[pos].first.second);
            pos--;
        }
        auto v1 = queryLeft(0, 0, S-1, right, INF);
        Db(v1.first);
        v1.first = right - v1.first;
        auto v2 = querySize(0, 0, S-1, -INF, right);
        Db(i, channels[i].first.first, channels[i].first.second);
        Db(v1.first);
        Db(v2.first);
        offer((ll) v1.first * channels[i].second.second, v1.second, channels[i].second.first);
        offer((ll) v2.first * channels[i].second.second, v2.second, channels[i].second.first);
    }
    if (first)
    {
        pos = M - 1;
        for (int i = N - 1; i >= 0; i--)
        {
            int left = videos[i].first.first;
            int right = videos[i].first.second;
            while (pos >= 0 && channels[pos].first.first >= left)
            {
                put(0, 0, S-1, channels[pos].first, 1ll*channels[pos].second.second * (channels[pos].first.second - channels[pos].first.first), channels[pos].second.first);
                pos--;
            }
            auto v1 = queryGain(0, 0, S-1, -INF, right);
            offer(v1.first, videos[i].second, v1.second);
        }
    }
}

void neg(pi& p)
{
    int a = p.first;
    int b = p.second;
    p.first = -b;
    p.second = -a;
}

#define GETCHAR getchar


static char stdinBuffer[1 << 17];
static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = stdinDataEnd;
 
void readAhead(size_t amount)
{
    size_t remaining = stdinDataEnd - stdinPos;
    if (remaining < amount) {
       memmove(stdinBuffer, stdinPos, remaining);
       size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
       stdinPos = stdinBuffer;
       stdinDataEnd = stdinBuffer + remaining + sz;
       if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
         *stdinDataEnd = 0;
    }
}
 
bool Read(int &x)
{
    readAhead(16);
    
    x=0;
 
    while (*stdinPos<'0'||*stdinPos>'9'){++stdinPos;}
 
    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }
     
  //   cout<<x<<endl;
    return 1;
}

int main()
{
    rint(N); rint(M);
    ji(N)
    {
        rint(videos[i].first.first);
        rint(videos[i].first.second);
        videos[i].second = i + 1;
    }
    ji(M)
    {
        rint(channels[i].first.first);
        rint(channels[i].first.second);
        rint(channels[i].second.second);
        channels[i].second.first = i + 1;
    }
    solve();
    ji(N) neg(videos[i].first);
    ji(M) neg(channels[i].first);
    solve(false);
    printf("%lld\n", ans);
    if (ans > 0)
        printf("%d %d\n", idx1, idx2);
}