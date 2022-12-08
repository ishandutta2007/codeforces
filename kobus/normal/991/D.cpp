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

string s1,s2;
int n;

int memo[112][2][2];

int pd(int i,char u, char l){
    if(i==n-1)return 0;
    int &resp=memo[i][u=='0'][l=='0'];
    if(resp==-1){
        resp=pd(i+1,s1[i+1],s2[i+1]);
        if(u=='0'&&l=='0'&&s1[i+1]=='0')resp=max(resp,1+pd(i+1,'X',s2[i+1]));
        if(u=='0'&&l=='0'&&s2[i+1]=='0')resp=max(resp,1+pd(i+1,s1[i+1],'X'));
        if(s1[i+1]=='0'&&s2[i+1]=='0'&&u=='0')resp=max(resp,1+pd(i+1,'X','X'));
        if(s1[i+1]=='0'&&s2[i+1]=='0'&&l=='0')resp=max(resp,1+pd(i+1,'X','X'));
    }
    return resp;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);
     
    cin>>s1>>s2;
    n=s1.size();
    for(int i=0;i<n;i++){
        memo[i][0][0]=-1;
        memo[i][0][1]=-1;
        memo[i][1][0]=-1;
        memo[i][1][1]=-1;
    }
    cout<<pd(0,s1[0],s2[0])<<endl;

    return 0;
}