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
#define MAXN 112345
#define MAXM 1123456
#define INF LLONG_MAX/2
#define MOD 1000000007
#define cte 10002
#define MAX ULLONG_MAX
#define kada cout<<"karadola"<<endl;

int fre[11];

int fato[21];

int fat(int n){
    if(n==1 || n==0 )return 1;
    if(fato[n]!=0)return fato[n];
    return fato[n]=n*fat(n-1);

}

int ways(vector<int> freq, int size){
    //for(int i=0;i<freq.size();i++)cout<<freq[i]<<" ";
    //cout<<endl;
    int respar=fat(size);
    for(int i=0;i<freq.size();i++){
        respar=respar/fat(freq[i]);
    }
    //cout<<respar<<endl;
    return respar;
}

int sw(vector<int> freq,int size){
    //for(int i=0;i<freq.size();i++)cout<<freq[i]<<" ";
    //cout<<endl;
    int resp=0;
    if(freq[0]==0)return ways(freq,size);
    for(int i=1;i<freq.size();i++){
        if(freq[i]!=0){
            vector<int> aux=freq;
            aux[i]--;
            resp+=ways(aux,size-1);
        }
    }
    return resp;
}

int solve(int i, vector<int> freq, int size){
    int ans=0;
    if(i==10)return sw(freq,size);
    if(fre[i]==0){
        freq.pb(0);
        return solve(i+1,freq,size);
    }
    for(int j=1;j<=fre[i];j++){
        vector<int> aux=freq;
        aux.pb(j);
        ans+=solve(i+1,aux,size+j);
    }
    return ans;
}






int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);
     
    string s;
    cin>>s;

    for(int i=0;i<s.size();i++){
        fre[s[i]-'0']++;
    }
    vector<int> ini;
    cout<<solve(0,ini,0)<<endl;

    return 0;
}