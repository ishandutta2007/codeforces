#include <bits/stdc++.h>
using namespace std;

#define MAXN 1123456
#define int long long
#define pb push_back
#define inf INT_MAX
#define mp make_pair
#define pii pair<int,int>
#define f first
#define s second


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cin>>n;
    vector<pair<pair<int,int>,int>> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.pb(mp(mp(x,i),0));
    }
    sort(v.begin(),v.end());
    int last=n+2;
    int resp=0;
    int at=1;
    for(int i=0;i<n;i++){
        int com=v[i].f.f;
        if(com!=at){
            cout<<-1<<endl;
            return 0;
        }
        at++;
        int num=1;
        v[i].s=num;
        while(i<n-1 && v[i+1].f.f==com){i++;num++;v[i].s=num;}
        if(com==1)resp=num;
        if(num>last){
            cout<<-1<<endl;
            return 0;
        }
        last=num;
    }
    for(int i=0;i<n;i++)swap(v[i].f.f,v[i].f.s);
    sort(v.begin(),v.end());
    cout<<resp<<endl;
    for(int i=0;i<n;i++)cout<<v[i].s<<" ";
    cout<<endl;


    return 0;
 
}