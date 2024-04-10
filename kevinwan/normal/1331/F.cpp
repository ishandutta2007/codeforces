#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
vector<string> v={"H","HE","LI","BE","B","C","N","O","F","NE","NA","MG","AL","SI","P","S","CL","AR","K","CA","SC","TI","V","CR","MN","FE","CO","NI","CU","ZN","GA","GE","AS","SE","BR","KR","RB","SR","Y","ZR","NB","MO","TC","RU","RH","PD","AG","CD","IN","SN","SB","TE","I","XE","CS","BA","LA","CE","PR","ND","PM","SM","EU","GD","TB","DY","HO","ER","TM","YB","LU","HF","TA","W","RE","OS","IR","PT","AU","HG","TL","PB","BI","PO","AT","RN","FR","RA","AC","TH","PA","U","NP","PU","AM","CM","BK","CF","ES","FM","MD","NO","LR","RF","DB","SG","BH","HS","MT","DS","RG","CN","NH","FL","MC","LV","TS","OG"};
const int mn=1e6+10;
bool b[mn];
int main(){
    string s;
    cin>>s;
    int n=s.size();
    b[0]=1;
    for(int i=1;i<=n;i++){
        for(string t:v){
            if(t.size()>i)continue;
            bool gud=1;
            for(int j=0;j<t.size();j++)if(t[j]!=s[i-t.size()+j])gud=0;
            if(gud)b[i]|=b[i-t.size()];
        }
    }
    if(b[n])printf("YES");
    else printf("NO");
}