#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

 using namespace std;

 long long n,m,q,k,a[123445],b[1234],c[1234],x,y,ma,p;
 string s,l,te="abcdefghtjklm";
 char t[1234567];

 int main(){
 cin>>n>>m;
 cin>>s>>l;
 m=n-m;
 ma=m;
 for (int i=0; i<n; i++)
 t[i]=' ';

 for (int i=0; i<n; i++)
    if (s[i]==l[i] && m!=0) {
        m--;
        t[i]=s[i];
    }
 for (int i=0; i<n; i++){ 
    if (s[i]==l[i] && x<m && y<m && t[i]==' ') {x++; y++; t[i]=s[i];} else
    if (x<m && x<=y && t[i]==' ') {x++; t[i]=s[i];} else
    if (y<m && x>=y && t[i]==' ') {y++; t[i]=l[i];} else {
        if (t[i]==' '){
            for (int j=0; j<te.length(); j++)
                if (s[i]!=te[j] && l[i]!=te[j]) {t[i]=te[j]; break;}
        }
    }
 }
 x=0;
 y=0;
 for (int i=0; i<n; i++){
    if (t[i]==s[i]) x++;
    if (t[i]==l[i]) y++;
 }

 if (x==ma && y==ma) {
    for (int i=0; i<n; i++)
        cout<<t[i];
 }
 else cout<<-1;
    
      


    
    
 return 0;
}