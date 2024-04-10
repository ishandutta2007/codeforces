#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii 		vector<pii>
#define mi 			map<int,int>
#define mii			map<int,pii>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007LL
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
#include <unistd.h> // not included in bits/stdc++.h
#define int long
unsigned int mix(unsigned int a, unsigned int b, unsigned int c)
#undef int
{
    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    return c;
}
using namespace std;
int n,m,out[100005],f2=0,s,p[100005][2],v[100005],st[100005];
vi a[100005],b[100005];
void dfs(int node){
    v[node]=1;
    st[node]=1;
    for(auto i:b[node]){
        if(st[i]) {cout<<"Draw";exit(0);}
        if(!v[i])
        dfs(i);
    }
    st[node]=0;
}
void solve(){
    unsigned long seed = mix(clock(), time(NULL), getpid());
    srand(seed);
    cin>>n>>m;
    rep(i,1,n+1){
        int c;
        cin>>c;
        rep(j,0,c){
            int x;
            cin>>x;
            b[i].pb(x);
            a[x].pb(i);
            out[i]++;
        }
    }
    cin>>s;
    queue<pii> q;
    rep(i,1,n+1){
        if(out[i]==0){
            q.push({i,0});
            p[i][0]=1;
        }
    }
    while(!q.empty()){
        pii d=q.front();
        d.y^=1;
        q.pop();
        for(auto i:a[d.x]){
            if(p[i][d.y]==0){
                p[i][d.y]=1;
                q.push({i,d.y});
            }
        }
    }
    if(p[s][1]){
        cout<<"Win\n";
        int cur=s,f=1;
        while(sz(b[cur])){
            cout<<cur<<" ";
            f^=1;
            vi v;
            for(auto i:b[cur]){
                if(p[i][f]){
                    v.pb(i);
                }
            }
            random_shuffle(all(v));
            cur=v[0];
        }
        cout<<cur;
    }
    else{
        dfs(s);
        cout<<"Lose";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}