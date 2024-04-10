#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#define f first
#define s second
#define mp make_pair                                                        
#define ll long long

using namespace std;

string l;
char s[1234566];
long long x,z,a[1234567],b[1234567],s1,s2;

int main(){
    scanf("%s",s);
    int n=strlen(s);
    scanf("%d%d",&x,&z);

    for (int i=0; i<n; i++){
        s1=((s1*10)+(s[i]-'0'))%x;
        a[i]=s1;
    }
    s2=1;
    for (int i=n-1; i>=0; i--){
        b[i]=(((s[i]-'0')*s2)+b[i+1])%z;
        if (i!=0 && s[i]!='0' && b[i]==0 && a[i-1]==0 ) {
            cout<<"YES"<<endl;
            for (int j=0; j<i; j++)
                cout<<s[j];
            cout<<endl;
            for (int j=i; j<n; j++)
                cout<<s[j];
            return 0;
        }
        s2=(s2*10)%z;
    }
    cout<<"NO";
        






    return 0;
}