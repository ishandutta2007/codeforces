/*
We praise the saviour
Observe the ten commandments
Confess our sins

For time immortal
Man's mind gets inspired
By gift and faculty divine

Blind superstition
Religious liberty
Mitigate our sorrows

Living in a world of dreams
Don't fear the true
Image of a God

Infant Jesus was crucified
A memorial for our future
Our atrocity is now forgiven
Because he has done his penance

Hear me people of sighing
Sorrow of pain and regret
Left to the dead and dying
You, that not know me as yet

Christ passion

Medieval extravagance of Christianity
Foundation in all cultmysteries
Holy customs and wholesale hysteria
Creeds to transcendental

Defecation of human nature
Devour them up with blindness
They are fool adore in all clergy
And mindful in the grace of god

Christ passion

Mortal way of life
Rapture of the earth
Lift up your heads
In the day of his wrath

In the worst hour of life
Looking into the eyes of death
Extreme unction nears
Intensive incense is befooled

He gives you unimaginable joy
Certainty and faith
To find unutterable peace
Demand no sacrifice

Christ passion

Expect no wonders celestial child
He will behold your repentance
His prophet revealed to the wise
The great mystery of god

Persecution of Christians in blasphemy
Born by the scum of evil
Almighty father knows no thirst for revenge
Praise the saviour on all saints' day
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
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

vector<long> v;
long r;
string st;
long calc[1000];

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

/*v.push_back(1);
v.push_back(6);
v.push_back(8);
v.push_back(9);
do 
{
 r=0;
 for (int i=0;i<v.size();i++)
 r=r*10+v[i];
 cout<<r%7<<endl;
}
while (next_permutation(v.begin(),v.end()));
*/

cin>>st;
for (int i=0;i<st.size();i++)
{calc[st[i]-'0']++;}

calc[1]--;
calc[6]--;
calc[8]--;
calc[9]--;

v.push_back(1);
v.push_back(6);
v.push_back(8);
v.push_back(9);
for (int i=0;i<=9;i++)
 for (int j=0;j<calc[i];j++)
 v.push_back(i);
 
 long iter=0;
long s=0; 
do
{
 /*for (int i=0;i<v.size();i++)
 cout<<v[i];
 cout<<endl;
 ++iter;*/
 s=0;
 for (int i=0;i<v.size();i++)
 s=(s*10+v[i])%7;
 if (s==0){for (int i=0;i<v.size();i++)
 cout<<v[i];cout<<endl;
 cin.get();cin.get();
 return 0;}
}while (next_permutation(v.begin(),v.begin()+4));

//cout<<iter<<endl;

cin.get();cin.get();
return 0;}