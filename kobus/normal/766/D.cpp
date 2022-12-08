
#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define MAXN 1123456
#define INF INT_MAX
#define int long long
#define double long double
#define pii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define eps 1e-11
#define pi acos(-1)

map<string,int> m;

int n;
int pai[MAXN],peso[MAXN];
int opp[MAXN];

int find(int x){
    return pai[x]=(x==pai[x]?x:find(pai[x]));
}

void join(int x,int y){
    if((x=find(x))==(y=find(y)))return;
    if(peso[x]<peso[y])swap(x,y);
    peso[x]+=peso[y];pai[y]=x;
}

void init(){
    for(int i=0;i<n;i++)peso[pai[i]=i]=1;
}



int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    int ass,q;
    cin>>n>>ass>>q;

    init();
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        m[s]=i;
        opp[i]=-1;
        //cout<<s<<" "<<i<<endl;
    }
    for(int i=0;i<ass;i++){
        int t;
        string s1,s2;
        cin>>t>>s1>>s2;
        int a=m[s1],b=m[s2];
        a=find(a);b=find(b);
        //cout<<a<<" "<<b<<endl;
        //cout<<opp[a]<<" "<<opp[b]<<endl;
        if(t==1){
            if(opp[a]!=-1 && find(opp[a])==b)cout<<"NO"<<endl;
            else{
                cout<<"YES"<<endl;
                join(a,b);
                if(opp[a]!=-1 && opp[b]!=-1)
                    join(find(opp[a]),find(opp[b]));
                else if(opp[a]!=-1 && opp[b]==-1)
                    opp[b]=opp[a];
                else if(opp[a]==-1 && opp[b]!=-1)
                    opp[a]=opp[b];
            }
        }
        else{
            if(a==b)cout<<"NO"<<endl;
            else{
                cout<<"YES"<<endl;
                if(opp[a]==-1)opp[a]=b;
                if(opp[b]==-1)opp[b]=a;
                join(opp[a],b);
                join(opp[b],a);
            }
        }
        a=find(a);b=find(b);
        //cout<<a<<" "<<b<<endl;
        //cout<<opp[a]<<" "<<opp[b]<<endl;
    }
    for(int i=0;i<q;i++){
        string s1,s2;
        cin>>s1>>s2;
        int a=m[s1],b=m[s2];
        a=find(a);
        b=find(b);
        if(a==b)cout<<1<<endl;
        else if(opp[a]!=-1 && find(opp[a])==b)cout<<2<<endl;
        else cout<<3<<endl;
    }


    return 0;
 
}