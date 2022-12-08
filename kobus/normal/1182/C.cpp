#include <bits/stdc++.h>
using namespace std;
#define INF 1'000'000'001
#define f first
#define s second
#define pb push_back
#define MAXN 1123456
#define pii pair<int,int>
#define pdd pair<double,double>
#define one 1
#define int long long
#define mp make_pair
#define ld long double
#define double long double
#define MOD 1000000007

set<char> vol={'a','e','i','o','u'};

map<pair<int,char>,multiset<string>> m;
map<int,multiset<string>> m2;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(2);
    cout.setf(ios::fixed);

    int n;
    cin>>n;

    multiset<pair<string,string>> msmmsm;
    multiset<pair<string,string>> msm;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int numvol=0;
        char last=0;
        for(char c:s){
            if(vol.find(c)!=vol.end()){
                numvol++;
                last=c;
            }
        }
        m[mp(numvol,last)].insert(s);
        m2[numvol].insert(s);
    }

    for(auto x:m){
        while(x.s.size()>1){
            string a=*x.s.begin();
            m2[x.f.f].erase(m2[x.f.f].find(*x.s.begin()));
            x.s.erase(x.s.begin());
            string b=*x.s.begin();
            m2[x.f.f].erase(m2[x.f.f].find(*x.s.begin()));
            x.s.erase(x.s.begin());
            msmmsm.insert(mp(a,b));
        }
    }
    for(auto x:m2){
        while(x.s.size()>1){
            string a=*x.s.begin();
            x.s.erase(x.s.begin());
            string b=*x.s.begin();
            x.s.erase(x.s.begin());
            msm.insert(mp(a,b));
        }
    }
    vector<string> resp;
    while(msmmsm.size()>0){
        pair<string,string> a=*msmmsm.begin();
        msmmsm.erase(msmmsm.begin());
        pair<string,string> b;
        if(msm.size()>0){
            b=*msm.begin();
            msm.erase(msm.begin());
        }
        else if(msmmsm.size()>0){
            b=*msmmsm.begin();
            msmmsm.erase(msmmsm.begin());
        }
        else break;
        resp.pb(b.f);
        resp.pb(a.f);
        resp.pb(b.s);
        resp.pb(a.s);
    }
    cout<<resp.size()/4<<endl;
    for(int i=0;i<resp.size();i+=2){
        cout<<resp[i]<<" "<<resp[i+1]<<endl;
    }


    return 0;
}