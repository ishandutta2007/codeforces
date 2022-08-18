/*
All within my hands
Squeeze it in, crush it down
All within my hands
Hold it dear, hold it suffocate

All within my hands
Love to death, smack you 'round and 'round and
All within my hands
Beware

Love is control
I'll die if I let go

Hate me now
Kill all within my hands
Hate me now
Crush all within my hands
Squeeze all within my hands
Choke all within my hands
Hate me now
Trap all within my hands
Hurry up and hate me now
Kill all within my hands

All within my hands
Take your fear, pump me up
All within my hands
Let you run, then I pull your leash

All within my hands
Under thumb, under to myself
All within my hands
Beware

Hate me now
Kill all within my hands
Hate me now
Crush all within my hands
Squeeze all within my hands
Choke all within my hands
Hate me now
Trap all within my hands
Hurry up and hate me now
Kill all within my hands again

I'll die if I let go
Control is love, love is control
I'll die if I let go
Control is love, love is control

I will only let you breath
My air that you receive
Then we'll see if I let you love me
Kill Kill Kill Kill Kill
*/

#include <math.h>
#include <string>
#include <iostream>
#include<algorithm>
//#include <stdio.h>
//#include <fstream>
#define M_PI        3.14159265358979323846
using namespace std;
double a,b;
long tests;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>tests;cout.precision(10);
for (;tests;--tests)
{cin>>a>>b;if (a==0&&b==0)a=1;
if (b==0&&a!=0)a=1;else 
if (a==0&&b!=0)a=0.5;else  
if (a!=0&&b!=0){
b*=4;if (a<=b)a=(b+a/2)/b/2;
else a=(a-b)/a+(b+b/2)*b/a/2/b;}
cout<<fixed<<a<<endl;}

cin.get();cin.get();
return 0;}