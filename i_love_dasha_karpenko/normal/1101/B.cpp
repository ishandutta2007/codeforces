#include <bits/stdc++.h>

using namespace std;
#define DIM 100000007.0
typedef pair<long long,long long> pairll;
long long n,i=0,j;
string str,newstr="";
int main()
{
    getline(cin,str);
    j = str.length()-1;
    while (str[i]!='[' && i<=str.length())i++;

    while(str[i]!=':' && i<=str.length())i++;
    while(str[j]!=']' && j>=0)j--;
    while(str[j]!=':' && j>=0)j--;
    if (i==str.length() ||i>j || i==j|| j==0){
        cout<<-1<<endl;
        return 0;
    }
    newstr+="[:";


    while (i<j){
        if (str[i]=='|')newstr+=str[i];
        i++;
    }
    newstr+=":]";
    cout<<newstr.length();
}