#include <bits/stdc++.h>
using namespace std;

void init(){
    #ifndef ONLINE_JUDGE
    freopen ("in.txt","r",stdin);
    freopen ("out.txt","w",stdout);
    #else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #endif
}

typedef long long int  li;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<li> vli;
typedef vector<bool> vb;
typedef pair<int,int> ii;

#define pb push_back
#define mp make_pair
#define ALL(x) x.begin(), x.end()
#define ALLr(x) x.rbegin(), x.rend()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define INF 1000000000
#define LIM 1000000
#define MOD 1000000007

int main(){
    init();
    li res = 0ll;
    int N, K, i, done = 0;
    cin >> N >> K;

    vector<ii> arr(N);
    vb taken(N, false);
    vb job(K+1, false);

    for(i=0; i<N; i++)
    	cin>>arr[i].second;
    for(i=0; i<N; i++)
    	cin>>arr[i].first;
    sort(ALL(arr));

    for(i=N-1; i>=0; i--)
    	if(job[arr[i].second]==false)
    		job[arr[i].second] = true, done++, taken[i] = true;

    for(i=0; i<N && done<K; i++)
    	if(taken[i]==false)
    		res += (li)arr[i].first, done++;

    cout<<res;

    return 0;
}