/*
Hello, 
Is there anybody in there? 
Just nod if you can hear me 
Is there anyone home? 

Come on 
Now 
I hear you're feeling down 
I can ease your pain 
Get you on your feet again 

Relax 
I'll need some information first 
Just the basic facts 
Can you show me where it hurts? 

There is no pain you are receding 
A distant ship's smoke on the horizon 
You are only coming through in waves 
Your lips move 
But I can't hear what you're saying 

When I was a child I had a fever 
My hands felt just like 
Two balloons 
Now I've got that feeling once again 
I can't explain 
You would not understand 
This is not how I am 

I... Have become comfortably numb 

O.K. 
Just a little pin prick 
There'll be no more aaaaaaaah! 
But you may feel a little sick 

Can you stand up? 
I do believe it's working 
Good 
That'll keep you going through the show 
Come on 
It's time to go 

There is no pain you are receding 
A distant ship's smoke on the horizon 
You are only coming through in waves 
Your lips move 
But I can't hear what you're saying 

When I was a child 
I caught a fleeting glimpse 
Out of the corner of my eye 

I turned to look but it was gone 
I cannot put my finger on it now 
The child is grown 
The dream is gone 
I... Have become comfortably numb 
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-6
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
//#define bsize 250
#define clone agsdahfaassdg

using namespace std;

string st;
vector<string> vec;
string temp;
long q;
long dep;
void showw(string st,long dep)
{
     for (int i=0;i<dep*2;i++)
     cout<<" ";
     cout<<st;
     cout<<endl;
}

int main(){
//freopen("experimental.in","r",stdin);
//freopen("experimental.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
for (int i=0;i<st.size();i++)
{
 if (st[i]=='<')
 {
  q=i;
  temp="";
  temp+=st[i];
  while (st[q]!='>'){++q;temp+=st[q];}
  vec.push_back(temp);
 }   
}

for (int i=0;i<vec.size();i++)
{
 if (vec[i].size()==4)dep--;
 showw(vec[i],dep);
 if (vec[i].size()==3)dep++;
}

cin.get();cin.get();
return 0;}