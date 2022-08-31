/*
Once we lived in harmony, but it seems so distance now.
Even though it wasnt long ago, were all doomed to
Plague and death. Working hard from dawn til dusk. but
That aint enough for him Product of unholy love, untrue
Brother of a king.

Know that youll fail, now hear us hail
Your brother that you killed.

Hail to the king that brought peace to us all. Rise from
Your grave, hear our call. Well not forget that you once
Saved our land. Killed by your own brothers hand.

Pure evil and cruelty, the true nature of your soul.
Mercy and responsibility, words that you cant understand.
Your quest for total control will only end in your own fall.
We will fight for our freedom, and our right to live.

Do it your way, soon you will pay
Debts with your own blood.

Stars so bright, dance in the night
Day come soon, hide the moon
Stars so bright dance in the night
Day come soon, killing the moon

Morning breaks its time to march, to the castle of betrayal.
Bring your sword, wield your armour, we wont take this anymore.
Kill the tyrant he must die, for his falseness and his crimes.
Strike him down, and slay his guards, and his ministers as well.

Done it your way, now you will pay
Debts with your own blood.

Hail to the king!
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
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256
#define double long double

using namespace std;

long n,k;
char c;
long ans;
long calc[2000];

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>k;
k*=2;
for (int i=1;i<=16;i++)
{
    cin>>c;calc[c]++;
    if (c!='.'&&calc[c]>k)ans=1;
}
if (ans)cout<<"NO"<<endl;
else cout<<"YES"<<endl;

cin.get();cin.get();
return 0;}