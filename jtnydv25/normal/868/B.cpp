#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pb push_back

int pos[3];
int main(){
	int h, m, s, t1, t2;
	cin >> h >> m >> s >> t1 >> t2;
	h %= 12;
	t1 %= 12;
	t2 %= 12;

	pos[0] = h * 3600 + m * 60 + s;
	pos[1] = (m * 60 + s) * 12;
	pos[2] = s * 720;
	t1 *= 3600;
	t2 *= 3600;
	sort(pos, pos + 3);

	if(t1 >= pos[0] && t1 <= pos[1] && t2 <= pos[1] && t2 >= pos[0]){
		cout << "YES";
		return 0;
	}

	if(t1 >= pos[1] && t1 <= pos[2] && t2 <= pos[2] && t2 >= pos[1]){
		cout << "YES";
		return 0;
	}

	if((t1 >= pos[2] || t1 <= pos[0]) && (t2 <= pos[0] || t2 >= pos[2])){
		cout << "YES";
		return 0;
	}
	cout << "NO";
}