#include <bits/stdc++.h>
using namespace std;

#define MAXN 212345
#define int long long
#define pb push_back
#define inf LLONG_MAX
#define mp make_pair
#define pii pair<int,int>
#define f first
#define s second

vector<int> testa(int at,vector<set<int>> v){
    //cout<<at<<endl;
    vector<int> nada;
    vector<int> resp={at};
    //cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        //cout<<"inseriu "<<at<<endl;
        //cout<<"conjuntos: "<<endl;
        for(auto x:v){
            //for(auto y:x)cout<<y<<" ";
            //cout<<endl;
        }
        //cout<<i<<endl;
        for(auto &x:v){
            if(x.find(at)!=x.end())x.erase(at);
        }
        //cout<<"conjuntos: "<<endl;
        for(auto x:v){
            //for(auto y:x)cout<<y<<" ";
            //cout<<endl;
        }
        at=-1;
        for(auto x:v){
            if(x.size()==1){
                if(at!=-1)return nada;
                else at=*x.begin();
            }
        }
        if(at==-1)return nada;
        resp.pb(at);
    }
    //cout<<"cabo"<<endl;
    return resp;
}

bool tacerto(vector<int> &v,vector<set<int>> &vv){
    //for(auto x:v)cout<<x<<" ";
    //cout<<endl;
    vector<int> com;
    for(auto x:vv){
        int lugar=0;
        for(int i=0;i<v.size();i++){
            if(x.find(v[i])!=x.end()){
                lugar=i;
                break;
            }
        }
        for(int j=lugar;j<lugar+x.size();j++){
            if(x.find(v[j])==x.end()){
                //for(auto y:x)cout<<y<<" ";
                //cout<<endl;
                return 0;
            }
        }
        com.pb(lugar+x.size()-1);
    }
    sort(com.begin(),com.end());
    for(int i=0;i<com.size();i++){
        //cout<<com[i]<<" "<<i<<endl;
        if(com[i]!=i+1)return 0;
    }
    return 1;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        //cout<<"aa "<<t<<endl;
        int n;
        cin>>n;
        //cout<<n<<endl;
        vector<set<int>> v;
        for(int i=0;i<n-1;i++){
            int m;
            cin>>m;
            //cout<<m<<endl;
            set<int> sla;
            for(int j=0;j<m;j++){
                int x;
                cin>>x;
                //cout<<x<<endl;
                sla.insert(x);
            }
            v.pb(sla);
        }
        //cout<<"leu aq"<<endl;
        vector<int> resp;
        for(int i=1;i<=n;i++){
            resp=testa(i,v);
            if(resp.size()>0 && tacerto(resp,v)){
                break;
            }
        }
        //cout<<resp.size()<<endl;
        for(auto x:resp)cout<<x<<" ";
        cout<<endl;

    }



    
    return 0;
 
}