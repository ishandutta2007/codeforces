#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 212345
#define INF INT_MAX/2
#define MOD 1000000007
#define p 41
#define LOGMAXN 20


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(1);
    cout.setf(ios::fixed);

    int q;
    cin>>q;
    set<int> a,b,c;
    int resp=1;
    for(int i=0;i<q;i++){
        string s;
        int n;
        cin>>s>>n;
        if(s=="ADD"){
            if(a.size()!=0 && *a.rbegin()>n)a.insert(n);
            else if(c.size()!=0 && *c.begin()<n)c.insert(n);
            else b.insert(n);
        }
        else{
            if(a.find(n)!=a.end() && n==*a.rbegin()){
                a.erase(n);
                while(b.size()!=0){
                    if(*b.begin()<n){
                        resp=0;
                    }
                    else if(*b.begin()>n){
                        c.insert(*b.begin());
                    }
                    b.erase(*b.begin());
                }
            }
            else if(a.find(n)!=a.end())resp=0;
            else if(c.find(n)!=c.end() && n==*c.begin()){
                c.erase(n);
                while(b.size()!=0){
                    if(*b.begin()>n){
                        resp=0;
                    }
                    else if(*b.begin()<n){
                        a.insert(*b.begin());
                    }
                    b.erase(*b.begin());
                }
            }
            else if(c.find(n)!=c.end())resp=0;
            else{
                resp*=2;
                resp%=MOD;
                while(b.size()!=0){
                    if(*b.begin()<n){
                        a.insert(*b.begin());
                    }
                    else if(*b.begin()>n){
                        c.insert(*b.begin());
                    }
                    b.erase(*b.begin());
                }
            }
        }
    }
    resp*=b.size()+1;
    resp%=MOD;
    cout<<resp<<endl;
    return 0;
}