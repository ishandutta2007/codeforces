#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef pair<long long,long long> pii;
#define int long long
#define INF LLONG_MAX/2
#define MOD 1000000007
#define MAXN 812345
#define LOGMAXN 21

pair<pii,int> q[31];

int threeto[31];
int t2(int x){
    if(x==0)return 1;
    return threeto[x]=3*t2(x-1);
}

string st(int i){
    if(i==0)return "MW";
    if(i==1)return "LW";
    return "LM";
}

bool comp(pair<pii,pii> a,pair<pii,pii> b){
    if(a.f!=b.f)return a.f<b.f;
    return a.s.s>b.s.s;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout.precision(4);
    //cout.setf(ios::fixed);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>q[i].f.f>>q[i].f.s>>q[i].s;
    }
    //differences and original numbers
    vector<pair<pii,pii> > a(t2(n/2));
    for(int i=0;i<t2(n/2);i++){
        int aux=i;
        int n1=0,n2=0,n3=0;
        for(int j=0;j<n/2;j++){
            if(aux%3==0){n2+=q[j].f.s;n3+=q[j].s;}
            if(aux%3==1){n1+=q[j].f.f;n3+=q[j].s;}
            if(aux%3==2){n1+=q[j].f.f;n2+=q[j].f.s;}
            aux=aux/3;
        }
        a[i].f.f=n2-n1;
        a[i].f.s=n3-n2;
        a[i].s.f=i;
        a[i].s.s=n1;
    }
    vector<pair<pii,pii> > b(t2((n+1)/2));
    for(int i=0;i<t2((n+1)/2);i++){
        int aux=i;
        int n1=0,n2=0,n3=0;
        for(int j=n/2;j<n;j++){
            if(aux%3==0){n2+=q[j].f.s;n3+=q[j].s;}
            if(aux%3==1){n1+=q[j].f.f;n3+=q[j].s;}
            if(aux%3==2){n1+=q[j].f.f;n2+=q[j].f.s;}
            aux=aux/3;
        }
        b[i].f.f=n2-n1;
        b[i].f.s=n3-n2;
        b[i].s.f=i;
        b[i].s.s=n1;
    }
    //for(int i=0;i<a.size();i++){
    //    cout<<a[i].f.f<<" "<<a[i].f.s<<" "<<a[i].s.f<<" "<<a[i].s.s<<endl;
    //}
    //cout<<"os bes"<<endl;
    //for(int i=0;i<b.size();i++){
    //    cout<<b[i].f.f<<" "<<b[i].f.s<<" "<<b[i].s.f<<" "<<b[i].s.s<<endl;
    //}
    sort(a.begin(),a.end(),comp);
    sort(b.begin(),b.end(),comp);
    pair<pair<pii,pii>,pair<pii,pii> > cand;
    cand.f.f.f=INF;
    for(int i=0;i<a.size();i++){
        pair<pii,pii> k=a[i];
        k.f.f=-k.f.f;
        k.f.s=-k.f.s;
        k.s.f=-INF;
        k.s.s=-INF;
        if(lower_bound(b.begin(),b.end(),k)==b.end())
            continue;
        k=*lower_bound(b.begin(),b.end(),k);
        //cout<<k.f.f<<" "<<k.f.s<<" "<<k.s.f<<" "<<k.s.s<<endl;
        if(k.f.f==-a[i].f.f&&k.f.s==-a[i].f.s){
            int summe=a[i].s.s+k.s.s;
            //cout<<summe<<endl;
            int sumhe=cand.f.s.s+cand.s.s.s;
            if(cand.f.f.f==INF||summe>sumhe)
                cand=mp(a[i],k);
        }   
    }
    if(cand.f.f.f==INF){
        cout<<"Impossible"<<endl;
        return 0;
    }
    int num=cand.f.s.f;
    for(int i=0;i<n/2;i++){
        cout<<st(num%3)<<endl;
        num=num/3;
    }
    num=cand.s.s.f;
    for(int i=0;i<(n+1)/2;i++){
        cout<<st(num%3)<<endl;
        num=num/3;
    }

    return 0;
}