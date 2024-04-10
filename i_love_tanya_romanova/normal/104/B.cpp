/*
Can't you see
That in the world we live in
Political lies
Are just corporate decisions
They'll take away
All the hopes, not their promises
They'll put an end to this
Land of the livin

Look at the lost souls
They seem so black
Look at the lost souls
Souls of black

They got control
Of the heart of a nation
Their social bribes
Seem so graciously
As time goes by
'Cause time as you can see
Will slowly die for you and me

Look at the lost souls
They seem so black
Look at the lost souls
Souls of black

So put an end
To this idolization
Antagonizing so commonly
Open your eyes
'Cause the lie's there so plain to see
Life goes on
There's no guarantees

Look at the lost souls
They seem so black
Look at the lost souls
Souls of black

They're bleeding so black
*/

#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define y1 aasdfasdfasdf
using namespace std;
long long n,ans,ar[100000];
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for (int i=1;i<=n;i++)
{cin>>ar[i];ans+=(ar[i]-1)*(i);}
cout<<ans+n<<endl;
cin.get();cin.get();cin.get();
return 0;
}