/*
Crucifixion, peasants bound to the cross
Heartless judgement, tyrannical laws
Among the jurists pangs of conscience arise
Conspiracy begins, the crucifier must fall

Assassination was attempted but failed
The conspirators are captured and jailed
Enraged by the plot now he vows his revenge
Hunt them down, seek their death, merciless

Collaborators face a summary trial
They are guilty there can be no denial
Convicted plotters face the hammer and nail
The traitors will be punished, the traitors will die

Their compunction, a sentence of death
Thoughts of mercy are replaced by dread
Punishment for traitors, swift and severe
Kill them all, they will die, crucify

Avenged, the crucifier has returned to kill
Vengeance, the betrayers bound and hung by nails
Avenged, the crucifier has returned to kill
Revenge, their betrayal only brought them hell

Punctured by piercing, the beam dripping blood
As a deterrent they are left there for months
Their agonizing deaths will serve to warn the rest
Betrayers will be hunted, betrayers will die

Wretched traitors, sun cooking their flesh
Rotting slowly they're begging for death
Transfixed by iron only bones will remain
He will hunt, hell's pursuit, execute

Avenged, the crucifier has returned to kill
Vengeance, the betrayers bound and hung by nails
Avenged, the crucifier has returned to kill
Revenge, their betrayal only brought them hell

No remorse for their deaths
No one will be spared from this fate
Hammer spikes through their hands
Penetrate the soles of their feet

Plant the stakes in the ground
Raise the crosses of the condemned
Proclaim judgement with blood
Triumph for the killers of men

Avenged, the crucifier has returned to kill
Vengeance, the betrayers bound and hung by nails
Avenged, the crucifier has returned to kill
Revenge, their betrayal only brought them hell

Avenged, the crucifier has returned to kill
Vengeance, the betrayers bound and hung by nails
Avenged, the crucifier has returned to kill
Revenge, their betrayal only brought them hell
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
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long long n,lst,ar[200000],bst;
long long ttl;

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>lst;
for (int i=1;i<=n;i++)
cin>>ar[i];
bst=ar[1];
for (int i=1;i<=n;i++)
bst=min(bst,ar[i]);
if (bst>5)
for (int i=1;i<=n;i++)
{ar[i]-=bst-3;ttl+=bst-3;}

while (ar[lst])
{
--ar[lst];
--lst;++ttl;
if (lst==0)lst=n;
}
ar[lst]=ttl;
for (int i=1;i<=n;i++){
    if (i-1)cout<<" ";
    cout<<ar[i];
}
cout<<endl;
//cout<<lst<<endl;

cin.get();cin.get();
return 0;}