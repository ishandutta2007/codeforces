#include <bits/stdc++.h>

using namespace std;
#define DIM 107
#define INF 10000000000007
typedef pair<long,long> pairll;
long long n,s,sum,k,cn=0,flag=0;;
string str,newstr="";
int main() {
    //freopen("b.in", "r", stdin);
	//freopen("b.out", "w", stdout);
	getline(cin,str);
	cin>>k;

    for (int i = 0;i<str.length();i++){
        if (str[i]!='*' && str[i]!='?')cn++;
    }
    if (cn>=k){
        for (int i =0;i<str.length() && cn>k;i++){
            if (str[i]=='*' || str[i]=='?'){
                cn--;
                str[i-1]='(';
            }
        }
        if (cn==k){
            for (int i = 0;i<str.length();i++){
                if (str[i]!='*' && str[i]!='(' && str[i]!='?' && str[i]!='/n')
                    newstr+=str[i];
            }
            cout<<newstr;
        }
        else{
            cout<<"Impossible";
        }
    }
    else if (cn<k){
        for (int i = 0;i<str.length();i++){
            if (str[i]=='*'){
                flag=1;
                for (int j = 0;j<i;j++){
                    if (str[j]!='?' && str[j]!='/n')
                        newstr+=str[j];
                }
                for (int j = 0;j<(k-cn);j++)
                    newstr+=str[i-1];
                for (int j = i+1;j<str.length();j++){
                    if (str[j]!='*' && str[j]!='?' && str[j]!='/n')newstr+=str[j];
                }
                break;
            }
        }
        if (flag==0){
            cout<<"Impossible";
        }
        else{
            cout<<newstr;
        }
    }
    //cout<<0;
    return 0;
}