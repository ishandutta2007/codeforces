/*
I don't wanna be your friend
I just wanna be your lover
No matter how it ends
No matter how it starts

Forget about your house of cards
And I'll do mine
Forget about your house of cards
And I'll do mine

And fall off the table, get swept under

Denial, denial

The infrastructure will collapse
Voltage spikes
Throw your keys in the bowl
Kiss your husband goodnight

Forget about your house of cards
And I'll do mine
Forget about your house of cards
And I'll do mine

Fall off the table, get swept under

Denial, denial
Denial, denial

Your ears should be burning
Denial, denial
Your ears should be burning
*/

#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
using namespace std;

vector <long long> v[3000];
long long h[200000],pw[200000];
string st,st1,st2;
long l1,l2,l,ans,fl,g1[20000],g2[20000];

long long gethash(long a,long b)
{
return (h[b+1]-h[a])*pw[st.size()-b+1];
       }
       
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

cin>>st;
cin>>st1>>st2;
/*for (int i=1;i<=2000;i++)
st+='a';
st1=st2="a";
*/
pw[0]=1;
for (int i=1;i<=3000;i++)pw[i]=pw[i-1]*29;

for (int i=1;i<=st.size();i++)h[i]=h[i-1]+st[i-1]*pw[i];

l=st.size();
l1=st1.size();
l2=st2.size();


for (int i=0;i<=l-l1;i++)
{fl=0;
 for (int j=0;j<l1;j++)if (st1[j]!=st[i+j]){fl++;break;}
 if (fl==0)g1[i]=1; 
}

for (int i=0;i<=l-l2;i++)
{fl=0;
 for (int j=0;j<l2;j++)if (st2[j]!=st[i+j]){fl++;break;}
 if (fl==0)g2[i+l2-1]=1; 
}

long lll=max(l1,l2);

for (int i=0;i<l;i++)
for (int j=i;j<l;j++)
if (g1[i]&&g2[j]&&(j-i+1>=lll))
{v[j-i+1].push_back(gethash(i,j));
                 }

/*
for (int i=0;i<8;i++)
{for (int j=0;j<v[i].size();j++)
{cout<<v[i][j]<<endl;
 }
 cout<<endl;
}
*/

for (int i=1;i<=l;i++)
{sort(v[i].begin(),v[i].end());
 if (v[i].size())ans++;
 for (int j=1;j<v[i].size();j++)
 if (v[i][j]!=v[i][j-1])++ans;
}
cout<<ans<<endl;
cin.get();cin.get();
return 0;
}