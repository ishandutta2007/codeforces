/*
Don't want your number
Don't want your name
Don't want your colour...
Don't want your politics
Don't want your cause
Don't believe what you believe
Don't want to wear your emblem
Don't want your cult or sect
Don't want your faith
Don't want your respect
Don't want your love
Don't want your praise
Don't want your stupid fashion
Don't want your phase 

Polarized - tell me what colours do you wear?
Your beliefs, polarized
I just don't care for what you care 

I just don't care for what you care 

Polarized - tell me what colours do you wear?
Your beliefs, polarized
I just don't care for what you care 

Don't want your number
Don't want your name
Don't want your colour...
Don't want your politics
Don't want your cause
Don't believe what you believe
Don't want to wear your emblem
Don't want your cult or sect
Don't want your faith
Don't want your respect
Don't want your love
Don't want your praise
Don't want your stupid fashion
Don't want your phase 

Polarized - tell me what colours do you wear?
Your beliefs, polarized
I just don't care for what you care 

Polarized - tell me what colours do you wear?
Your beliefs, polarized
I just don't care
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 2000

using namespace std;

long n,k,arp[400000][2],ans;
string st[10];
queue<pair<long, long> > qu;
long qa,qb;
pair<long, long> temp;

int main(){
//freopen("ascii.in","r",stdin);
//freopen("ascii.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
cin>>st[0];
cin>>st[1];
qu.push(make_pair(1,0));
arp[1][0]=1;

while (qu.size())
{
 temp=qu.front();
 qu.pop();
 qa=temp.first;qb=temp.second;
 
 if (qa>n){ans=1;break;}
 
 if (arp[qa][qb]>qa)continue;
 
 if (qa>0&&arp[qa-1][qb]==0&&st[qb][qa-2]=='-')// dwn
 {
  qu.push(make_pair(qa-1,qb));
  arp[qa-1][qb]=arp[qa][qb]+1;
 }
 
 if (qa<n&&arp[qa+1][qb]==0&&st[qb][qa]=='-')// up
 {
  qu.push(make_pair(qa+1,qb));
  arp[qa+1][qb]=arp[qa][qb]+1;
 }
 
 if (arp[qa+k][1-qb]==0&&(qa+k>n||st[1-qb][qa+k-1]=='-'))// jump
 {
  qu.push(make_pair(qa+k,1-qb));
  arp[qa+k][1-qb]=arp[qa][qb]+1;
 }
}

if (ans)cout<<"YES"<<endl;
else cout<<"NO"<<endl;

cin.get();cin.get();
return 0;}