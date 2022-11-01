#include<bits/stdc++.h>
using namespace std;

int N; char S[1000003]; int suf[1000003]; bool flg[1000003];
bool check(int mid){
	memset(flg , 0 , sizeof(flg)); flg[0] = 1;
	for(int i = 1 ; i <= N ; ++i)
		if(flg[i - 1]){
			if(S[i] != '*') flg[i] = 1;
			if(S[i] == 'P') flg[min(min(suf[i] - 1 , N) , i + mid)] = 1;
			if(S[i] == '*')
				if(suf[i] - i <= mid){
					flg[suf[i]] = 1;
					if(suf[suf[i]] - i <= mid)
						flg[min(min(suf[suf[suf[i]]] - 1 , N) , suf[i] + mid)] = 1;
				}
		}
	return flg[N];
}

signed main(){
	scanf("%d %s" , &N , S + 1); int cntb = 0 , cntd = 0; suf[N + 1] = 1e9;
	for(int i = N ; i ; --i){cntd += (S[i] == 'P'); cntb += S[i] == '*'; suf[i] = S[i + 1] == 'P' ? i + 1 : suf[i + 1];}
	if(cntd == 1){
		for(int i = 1 ; i <= N ; ++i)
			if(S[i] == 'P'){
				int cntl = 0 , cntr = 0 , tl = 0 , tr = 0;
				for(int j = i - 1 ; j ; --j) if(S[j] == '*'){++cntl; tl = i - j;}
				for(int j = i + 1 ; j <= N ; ++j) if(S[j] == '*'){++cntr; tr = j - i;}
				if(cntl == cntr) tl = min(tl , tr); else if(cntl < cntr){swap(cntl , cntr); swap(tl , tr);}
				cout << cntl << ' ' << tl << endl;
			}
	}else{
		int L = 1 , R = N; while(L < R){int mid = (L + R) >> 1; check(mid) ? R = mid : L = mid + 1;}
		cout << cntb << ' ' << L << endl;
	}
	return 0;
}