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
#define MAX ULLONG_MAX

int maxi=11234567;
bool ocp[11234567];
set<int> tirado;


void upd(int n){
    for(int i=1;i*n<maxi;i++){
        ocp[i*n]=1;
    }
}

void tira(int n){
    int cara=2;
    while(n!=1){
        if(n%cara==0){
            n=n/cara;
            if(tirado.find(cara)==tirado.end()){
                tirado.insert(cara);
                upd(cara);
            }
        }
        else cara++;
        if(cara*cara>n)cara=n;
    }
}

int pri=2;
int nxtpri(){
    if(!ocp[pri]){
        tira(pri);
        return pri;
    }
    while(ocp[pri])pri++;
    tira(pri);
    return pri;
}


int v[112345];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(1);
    cout.setf(ios::fixed);
    
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>v[i];

    bool free=0;
    for(int i=0;i<n;i++){
        if(free){
            cout<<nxtpri()<<" ";
            continue;
        }
        if(!ocp[v[i]]){
            tira(v[i]);
            cout<<v[i]<<" ";
        }
        else{
            free=1;
            int num=v[i];
            while(ocp[num])num++;
            tira(num);
            cout<<num<<" ";
        }
    }
    cout<<endl;

    return 0;

}