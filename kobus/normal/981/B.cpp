#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
#define double long double
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 1123456
#define INF LLONG_MAX
#define MOD 32416187567
#define cte 10002
#define MAX ULLONG_MAX

pii v[1123456];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    int n1;
    cin>>n1;
    for(int i=0;i<n1;i++){
        cin>>v[i].f>>v[i].s;
        v[i].s=-v[i].s;
    }
    int n2;
    cin>>n2;
    for(int i=n1;i<n1+n2;i++){
        cin>>v[i].f>>v[i].s;
        v[i].s=-v[i].s;
    }
    int n=n1+n2;
    sort(v,v+n);
    int resp=0;
    for(int i=0;i<n;i++){
        if(i==0 || v[i].f!=v[i-1].f)resp-=v[i].s;
    }

    cout<<resp<<endl;



}