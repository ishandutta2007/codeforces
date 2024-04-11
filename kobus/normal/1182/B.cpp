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

char ma[512][512];

int pro(vector<char> &v){
    if(v.size()==0||v[0]=='.')return -1;
    bool saiu=0;
    int resp=0;
    for(int i=0;i<v.size();i++){
        if(v[i]=='*'&&saiu)return -1;
        if(v[i]=='.')saiu=1;
        else resp++;
    }
    return resp;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(2);
    cout.setf(ios::fixed);

    int n,m;
    cin>>n>>m;
    int num=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>ma[i][j];
            num+=ma[i][j]=='*';
        }
    }
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            if(ma[i][j]!='*')continue;
            if(ma[i-1][j]=='.'||ma[i+1][j]=='.'||ma[i][j+1]=='.'||ma[i][j-1]=='.')continue;
            int counter=1;
            vector<char> par;
            for(int k=i+1;k<n;k++){
                par.pb(ma[k][j]);
            }
            int numpar=pro(par);
            if(numpar==-1)continue;
            counter+=numpar;
            par.clear();

            for(int k=i-1;k>=0;k--){
                par.pb(ma[k][j]);
            }
            numpar=pro(par);
            if(numpar==-1)continue;
            counter+=numpar;
            par.clear();

            for(int k=j+1;k<m;k++){
                par.pb(ma[i][k]);
            }
            numpar=pro(par);
            if(numpar==-1)continue;
            counter+=numpar;
            par.clear();

            for(int k=j-1;k>=0;k--){
                par.pb(ma[i][k]);
            }
            numpar=pro(par);
            if(numpar==-1)continue;
            counter+=numpar;
            if(counter==num){
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
            return 0;


        }
    }
    cout<<"NO"<<endl;


    return 0;
}