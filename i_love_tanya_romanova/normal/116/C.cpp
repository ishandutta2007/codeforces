/*
Help me if you can
It's just that this is not the way I'm wired, so could you please
Help me understand why
You've given in to all these reckless dark desires?

You're lying to yourself again, suicidal imbecile
Think about it, you put it on a faultline
What'll it take to get it through to you, precious?
I'm over this, why you wanna throw it away like this
Such a mess, I don't wanna watch you

Disconnect and self destruct, one bullet at a time
What's your rush now, everyone will have his day to die

Medicated, drama queen
Picture perfect numb belligerence
Narcissistic, drama queen
Craving fame and all its decadence

Lying through your teeth again, suicidal imbecile
Think about it, put it on a fault line
What'll it take to get it through to you precious?
I'm over this, why you wanna throw it away like this?
Such a mess, I don't wanna watch you

Disconnect and self destruct one bullet at a time
What's your rush now, everyone will have his day to die

They were right about you
They were right about you

Lying to my face again, suicidal imbecile
Think about it, you put on a fault line
What'll it take to get through to you precious?
I'm over this, why you wanna throw it away like this?
Such a mess, come to this, come to this

Disconnect and self destruct one bullet at a time
What's your hurry, everyone will have his day to die
If you choose to pull the trigger
Should your drama prove sincere
Do it somewhere far away from here
*/

#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <fstream>
#include <map>
#include <queue>
#include <algorithm>
#define y1 sgjkdf
using namespace std;
long q,n,arp[3000],s,ans,ar[2100][2100];
vector <long> pp;
void dfs(long a,long b)
{arp[a]=1;ans=max(ans,b);
 for (int i=1;i<=n;i++)
 if (ar[a][i]==1&&arp[i]==0)
 {dfs(i,b+1);
                            }
}
int main(){
   // freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);

cin>>n;

for (int i=1;i<=n;i++)
{cin>>q;
 if (q==-1)pp.push_back(i);
 else {ar[q][i]=1;
 ar[i][q]=1;}
}

for (int i=0;i<pp.size();i++)
{q=pp[i];
 s=0;
 dfs(q,1);
}
cout<<ans<<endl;
cin.get();cin.get();cin.get();
return 0;
}