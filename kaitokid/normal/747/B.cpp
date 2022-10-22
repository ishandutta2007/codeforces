#include <bits/stdc++.h>

using namespace std;
string s="",s1="AGCT";
char let[300];
int a[5];
int main()
{
  int n,mx=0;
  cin>>n;
 for(int i=0;i<n;i++)
 {cin>>let[i];
 if(let[i]=='?'){a[0]++;}
  if(let[i]=='A'){a[1]++;mx=max(mx,a[1]);}
   if(let[i]=='C'){a[2]++;mx=max(mx,a[2]);}
    if(let[i]=='G'){a[3]++;mx=max(mx,a[3]);}
     if(let[i]=='T'){a[4]++;mx=max(mx,a[4]);}

 }
    if(mx*4>n||((n-(mx*4))%4)!=0){cout<<"===";return 0;}
s.insert(s.begin(),(mx-a[1])+(n-(mx*4))/4,'A');
s.insert(s.begin(),mx-a[2]+(n-(mx*4))/4,'C');
s.insert(s.begin(),mx-a[3]+(n-(mx*4))/4,'G');
s.insert(s.begin(),mx-a[4]+(n-(mx*4))/4,'T');
int l=0;
for(int i=0;i<n;i++)
{if(let[i]=='?'){let[i]=s[l];l++;}
    }

for(int i=0;i<n;i++){cout<<let[i];}
    return 0;
}