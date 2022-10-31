#include <bits/stdc++.h>

using namespace std;
#define DIM 200
long long n,o=1,cn1=0,cn2=0,cn3=0,j;
char s;
vector<long long> A,B,C;
string str,str1,str2,str3;
int main()
{
    //freopen("b.in","r",stdin);
    //freopen("b.out","w",stdout);
    cin>>n;
    cin>>str;
    str1 = str;
    for (int i = 1;i<n;i++){
        if (str1[i]==str1[i-1] && str[i]!='.'){cn1++;str1[i]='.';}
    }
    cout<<cn1<<endl;;
    for (int i = 0;i<n;i++){
        if (str1[i]=='.'){
            if (str[i-1]!='G' && str[i+1]!='G')str1[i]='G';
            else if (str[i-1]!='B' && str[i+1]!='B')str1[i]='B';
            else str1[i]='R';
        }
    }
    cout<<str1<<endl;
}