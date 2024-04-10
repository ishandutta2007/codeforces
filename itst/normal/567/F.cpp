 #include<bits/stdc++.h>
#define int long long
using namespace std;

int ans[72][72] , numOp[72];

vector < int > num[72] , op[72];
map < string , int > opToNum;

bool ifOK(int l , int r , int que1 , int que2){
	for(int i = 0 ; i < numOp[que1] ; i++)
		switch(op[que1][i]){
			case 1:
				if(num[que1][i] < r && num[que1][i] > l || num[que1][i] == que2)
					return 0;
				break;
			case 2:
				if(num[que1][i] < r && num[que1][i] > l && num[que1][i] != que2)
					return 0;
				break;
			case 3:
				if(!(num[que1][i] == que2))
					return 0;
				break;
			case 4:
				if(!(num[que1][i] <= r && num[que1][i] >= l || num[que1][i] == que2))
					return 0;
				break;
			case 5:
				if(!(num[que1][i] < r && num[que1][i] > l) || num[que1][i] == que2)
					return 0;
		}
	for(int i = 0 ; i < numOp[que2] ; i++)
		switch(op[que2][i]){
			case 1:
				if(num[que2][i] < r && num[que2][i] > l || num[que2][i] == que1)
					return 0;
				break;
			case 2:
				if(num[que2][i] < r && num[que2][i] > l && num[que2][i] != que1)
					return 0;
				break;
			case 3:
				if(!(num[que2][i] == que1))
					return 0;
				break;
			case 4:
				if(!(num[que2][i] <= r && num[que2][i] >= l || num[que2][i] == que1))
					return 0;
				break;
			case 5:
				if(!(num[que2][i] < r && num[que2][i] > l) || num[que2][i] == que1)
					return 0;
		}
	return 1;
}

main(){
	opToNum.insert(make_pair(">" , 1));
	opToNum.insert(make_pair(">=" , 2));
	opToNum.insert(make_pair("=" , 3));
	opToNum.insert(make_pair("<=" , 4));
	opToNum.insert(make_pair("<" , 5));
	int N , K;
	for(cin >> N >> K ; K ; K--){
		int a , b , t;
		string s;
		cin >> a >> s >> b;
		t = opToNum.find(s)->second;
		if(a == b)
			if(t == 1 || t == 5){
				cout << 0;
				return 0;
			}
			else
				continue;
		num[a].push_back(b);
		op[a].push_back(t);
		num[b].push_back(a);
		op[b].push_back(6 - t);
		numOp[a]++;
		numOp[b]++;
	}
	ans[0][0] = 1;
	for(int i = 1 ; i <= N ; i++){
		for(int j = 2 * i ; j >= 2 ; j--)
			if(ans[j - 2][2 * i - j] && ifOK(j , 2 * N - 2 * i + j + 1 , j , j - 1))
				ans[j][2 * i - j] += ans[j - 2][2 * i - j];
		for(int j = 2 * i ; j >= 2 ; j--)
			if(ans[2 * i - j][j - 2] && ifOK(2 * i - j , 2 * N - j + 1 , 2 * N - j + 1 , 2 * N - j + 2))
				ans[2 * i - j][j] += ans[2 * i - j][j - 2];
		for(int j = 1 ; j < 2 * i ; j++)
			if(ans[2 * i - j - 1][j - 1] && ifOK(2 * i - j , 2 * N - j + 1 , 2 * i - j , 2 * N - j + 1))
				ans[2 * i - j][j] += ans[2 * i - j - 1][j - 1];
	}
	int all = 0;
	for(int i = 0 ; i <= 2 * N ; i++)
		all += ans[i][2 * N - i];
	cout << all / 3;
	return 0;
}