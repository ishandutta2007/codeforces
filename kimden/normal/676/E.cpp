#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define BOUND 2000000000000
int main()
{
	int n,k;
	string s;
	int qm=0;
	int a[100010];
	bool q[100010];
	ll d=0;
	cin >> n >> k;
	for(int i=0;i<=n;i++){
		cin >> s;
		if(s=="?"){
			qm++;
			a[i] = 0;
			q[i] = true;
		}else{
			sscanf(s.c_str(),"%d",&a[i]);
			q[i] = false;
		}
	}
	bool nowHuman = ((n+1-qm)%2==1);
	if(k==0){
		if(q[0]){
			if(nowHuman){
				cout << "Yes";
			}else{
				cout << "No";
			}
		}else{
			if(a[0]==0){
				cout << "Yes";
			}else{
				cout << "No";
			}
		}
		return 0;
	}else{ // k != 0
		d = a[n];
		for(int i=n-1;i>=0;i--){
			d *= k;
			d += a[i];
			d = min(d,BOUND);
			d = max(d,-BOUND);
		}
		if(qm==0){
			if(d==0){
				cout << "Yes";
			}else{
				cout << "No";
			}
			return 0;
		}
		if(((qm%2==0)&&(nowHuman))||((qm%2==1)&&(!nowHuman))){
			cout << "No";
		}else{
			cout << "Yes";
		}
	}
	return 0;
}