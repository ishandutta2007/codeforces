#include <bits/stdc++.h>

using namespace std;
#define DIM 100007
#define INF 1000000000000000007
#define MAXN 100007
typedef pair<long long, long long > pairll;
struct troinik{
    long long t,ind,nomer;
};
bool mycompare(troinik a,troinik b){
    if (a.t==b.t)return a.ind<b.ind;
    return a.t<b.t;
}
string str;
long double res = 0,cnnum = 0,numscn = 0;
int flag=0;
int main()
{
    //freopen("input.txt","r",stdin);
    getline(cin,str);
    str+='h';
    for (int i = 0;i<str.length();i++){
        if (str[i]>=48 && str[i]<=57 && flag == 0){
            flag = 1;
            cnnum = str[i]-48;
            numscn = 1;
        }
        else if (flag ==1){
            if ((str[i]<48 || str[i]>57) && str[i]!='.'){
                if (numscn==2)cnnum/=100;
                res+=cnnum;
                cnnum = 0;
                flag = 0;
                numscn = 0;
            }
            else if (str[i]=='.'){
                numscn = 0;

            }
            else{
                cnnum*=10;
                cnnum+=str[i]-48;
                numscn++;
            }
        }
    }
    long long r = res,cn=0;
    string g="";
    while(r>0){
        g+=r%10+48;
        cn++;
        r/=10;
        if (cn==3){
            cn = 0;
            g+='.';
        }
    }
    long long u = g.length()-1,m=0;
    if (g[0]=='.')m++;
    if (g[u]=='.')u--;
    for (int i = u;i>=m;i--)cout<<g[i];
    r = res;
    long double s = res-r;
    if (res<1)cout<<0;
    if (s!=0){

        cout<<'.';
        s*=100;
        if (s<=9){
            cout<<0;
        }
        cout<<s;
    }
    cout<<endl;
}