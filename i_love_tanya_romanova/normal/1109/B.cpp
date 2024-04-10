/*
History's shown you that answers can't be found above.
Life's great questions are tackled only by us.
Knowledge of mysteries that puzzle your learned men of the cloth.
We've explanations that men of God can't fathom.

Searching for your destiny
In a book that's not reality.
We solve the the Earth's problems
Through our science and technology.

Look back one thousand years when science was in its infancy.
The church had the word, the world was forced to heed.
How many times they led astray, their flock was shown no mercy.
"It's God's will", not good enough, minds were closed ignorantly.

We are here to shed the light,
And your "Savior" is powerless to fight.
You must realize that your theology is wrong
And we are right.
Accept it for it's proven,
And the truth is for all to see.
Scientifically we'll answer any question there could be.

Obviously you don't see that we've become your deities.
Can't you see that we are your new priesthood?
Blinded by your piety and impotent divinity,
Recoginize that we are your new priesthood!

Religious dogma that's confused and shackled you.
Searching through the good book not knowing what's the truth.
You're only innocent, raised servile and unaware.
Unconversant to what is really out there.

Humanity must be erudite but not only from books should it gain insight.
Through practice of sound philosophy comes cognizance of Man's own plight.
This you won't find in your church or your faith,
Though science has always attempted to explicate.

Obviously you don't see that we've become your deities.
Can't you see that we are your new priesthood?
Blinded by your piety and impotent divinity,
Recoginize that we are your new priesthood!

Intelligence is lacking in your realm.
That is why we've come to take the helm.

As you have seen, you cannot turn to God for the solution.
Mankind has thrust himself into a sick position, lack of vision.
To those who blanket and surround themselves with gullibility,
There will be severity.
Yet again we will achieve the answers because we are more than God.

As you kneel and pray,
Genuflect our way.
Try and feel your way
Without our guidance someday.

History's shown you that answers can't be found above.
Life's great questions are tackled only by us.
Knowledge of mysteries that puzzle your learned men of the cloth.
We've explanations that men of God can't fathom.

Searching for your destiny
In a book that's not reality.
We have solved the the Earth's problems
Through our science and technology.
We see the things that you can't find in your faith.
We are in command with men like Hawking leading the way.

Obviously you don't see that we've become your deities.
Can't you see that we are your new priesthood?
Blinded by your piety and impotent divinity,
Recoginize that we are your new priesthood!
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
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
#include <ctime>

#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 400031;

string st;

bool is_pal(string st){
	string temp=st;
	reverse(temp.begin(),temp.end());
	return (temp==st);
}

bool solve(string st,int cnt){
	if (cnt==1){
		for (int i=1;i<st.size();i++){
			string temp1="",temp2="";
			for (int j=0;j<st.size();j++){
				if (j<i)
					temp1+=st[j];
				else
					temp2+=st[j];
			}
			string t=temp2+temp1;
			if (t!=st&&is_pal(t))
				return true;
		}
		return false;
	}

	if (cnt==2){
		for (int i=1;i*2<=st.size();i++){
			string temp="";
			for (int j=0;j<i;j++)
				temp+=st[j];
			if (is_pal(temp)==false)
				return true;
		}
		return false;
	}

	return false;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>st;
    if (solve(st,1)){
    	cout<<1<<endl;
    	return 0;
    }

    if (solve(st,2)){
    	cout<<2<<endl;
    	return 0;
    }

    cout<<"Impossible"<<endl;

//    cin.get(); cin.get();
    return 0;
}