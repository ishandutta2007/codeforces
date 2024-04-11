#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;//We'll solve the problem incrementally, 
	//that is we'll first solve it for the first characer,
	// then we will add the second character and then the 3rd and so on
	int ans = 0;//answer == time at which the last girl surpassed all the guys
	int inq = 0;//the number of moves the last girl spent standing right after a different girl
	int streak = 0;//current streak of guys
	int guys = 0;//number of Ms
	//Observation 1: When adding a girl, if she ever stands after a different girl(before that girl passes all the guys)
	//then she will reach the end one moment later since it will pass each guy left right after the previous girl
	for(auto c : s) {
		if(c == 'M') streak++, guys++;//answer does not change streak increases by one
		else {//ansewr increases, streak of guys is reset
			//we want to find out whether this girl will ever reach the previous one
			//currently distance between this girl and the previous one is `streak`. Before their first meeting the new girl will pass a guy each second,
			//the distance decreases if the previous girl spends this moment after another girl
			if(guys != streak && inq >= streak) {//the previous girl spends at least streak moments standing after a girl so they will definitely meet at some point
				// == number of guys between them will eventually reach 0
				//this also can't happen if the previous girl was didn't have any guys to pass to begin with
				//in this case answer is equal to old answer + 1, because of Observation 1
				ans++;
			} else//since she never stands after a girl, she passes a guy each second, so answer == number of guys to pass
				ans = guys;
			inq = ans - guys;//this girl will need 
			streak = 0;//we use it to recompute the answer so resetting at the end
		}
	}
	cout << ans << '\n';
}