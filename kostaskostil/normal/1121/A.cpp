#include <iostream>
#include <vector>
using namespace std;

int technogoblet (vector<int> powers, vector<int> schools, vector<int> hacked, int schoolNum){
	int fakeSchoolNum = 0;
	vector<int> winners(schoolNum, -1);
	for(int i: hacked){
//            cout<<i<<" "<<schools[i]<<"\n";
		if(winners[schools[i]] == -1) winners[schools[i]] = i;
		else{
			if(powers[winners[schools[i]]] < powers[i]) winners[schools[i]] = i;
			fakeSchoolNum++;
		}
	}
	vector<int> realWinners(schoolNum, -1);
	for(int i = 0; i < powers.size(); i++){

		if(realWinners[schools[i]]==-1 or powers[realWinners[schools[i]]] < powers[i]){
			realWinners[schools[i]] = i;
		}
	}
	for(int i = 0; i < schoolNum; i++){
		if (realWinners[i] != -1)
		if (winners[i] != -1)
        if (powers[realWinners[i]] > powers[winners[i]])
            fakeSchoolNum++;
	}
	return fakeSchoolNum;
}

int main(){
	int n, m, k;
	cin >> n;
	cin >> m;
	cin >> k;
	vector<int> powers(n);
	for(int i = 0; i < n; i++){
		cin >> powers[i];
	}
	vector<int> schools(n);
	for(int i = 0; i < n; i++){
		cin >> schools[i];
		schools[i]--;
	}
	vector<int> hacked(k);
	for(int i = 0; i < k; i++){
		cin >> hacked[i];
		hacked[i]--;
	}
	cout << technogoblet(powers, schools, hacked, m);
	return 0;
}