#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 512345
#define INF LLONG_MAX
#define MOD 1000000007
#define cte 10002
#define MAX 21234


int v[112345];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);
    
    int n;
    cin>>n;
    n++;

    for(int i=0;i<n;i++)cin>>v[i];
    bool p=1; 
    for(int i=1;i<n;i++){
        if(v[i]>1 && v[i-1]>1)p=false;
        //cout<<v[i]<<" "<<v[i-1]<<endl;
    }
    if(p){
        cout<<"perfect"<<endl;
        return 0;
    }

    vector<int> p1;
    vector<int> p2;

    int num=2;
    p1.pb(0);
    int last=1;
    for(int i=1;i<n;i++){
        int pai=last;
        for(int j=0;j<v[i];j++){
            p1.pb(pai);
            last=num;
            num++;
        }
    }

    p2.pb(0);
    int lastfnum=0;
    int pai;

    for(int i=1;i<n;i++){
        lastfnum+=v[i-1];
        //cout<<lastfnum<<endl;
        int pai=lastfnum;
        for(int j=0;j<v[i];j++){
            p2.pb(pai);
            pai--;
            if(pai<=lastfnum-v[i-1])pai+=v[i-1];
        }
    }

    cout<<"ambiguous"<<endl;
    for(int i=0;i<p1.size();i++)cout<<p1[i]<<" ";
    cout<<endl;
    for(int i=0;i<p2.size();i++)cout<<p2[i]<<" ";
    cout<<endl;


    return 0;

}