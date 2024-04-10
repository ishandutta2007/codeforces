/*
Heyy heyy heyy yaaa [x6]

Johnny Cash
And PBR
Jack Daniels
Nascar
Facebook
Myspace
IPod
Bill Gates
Smith and Wesson
NRA
Firewater
Pale Face
Dimebag
Tupac
Heavy Metal
Hip-Hop

I am
What you fear most
I am
What you need
I am
What you made me
I am
The American dream

I'm not selling out
I'm buying in

I will not be forgotten
This is my time to shine
I've got the scars to prove it
Only the strong survive
I'm not afraid of dying
Everyone has their time
Life never favored weakness
Welcome to the pride

Disneyland
White House
JFK
And Mickey Mouse
John Wayne
Springsteen
Eastwood
James Dean
Coca-Cola
Pepsi
Playboy
Text me
NFL
NBA
Brett Favre
King James

I am
All American
I am
Living the dream
I am
What you fear most
I am
Anarchy

I'm not selling out
I'm buying in

I will not be forgotten
This is my time to shine
I've got the scars to prove it
Only the strong survive
I'm not afraid of dying
Everyone has their time
Life never favored weakness
Welcome to the pride

Since the dawn of time
Only the strong have survived
I will not be forgotten
Welcome to the pride

Heyy heyy heyy yaaa [x3]
Only the strong survive
Heyy heyy heyy yaaa [x3]
Welcome to the pride

I will not be forgotten
This is my time to shine
I've got the scars to prove it
Only the strong survive
I'm not afraid of dying
Everyone has their time
Life never favored weakness
Welcome to the pride
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
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
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long long n,q,a[200000],b[200000],qtime,qsongs,ttime;

int main(){
//freopen("knight.in","r",stdin);
//freopen("knight.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>q;
for (int i=1;i<=n;i++)
cin>>a[i]>>b[i];

qtime=0;
qsongs=0;

for (int i=1;i<=q;i++)
{
    cin>>ttime;
    while (qtime<ttime){++qsongs;qtime+=a[qsongs]*b[qsongs];}
    cout<<qsongs<<endl;
}
cin.get();cin.get();
return 0;}