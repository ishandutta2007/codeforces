#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
const int MAXL = 1 << 20;
typedef long long ll;

ll a[MAXN], b[MAXN];
int n, m;

void work1(){
	ll ans = 0;
	int p = b[1] & 31;
	ll q = b[1] >> 5;
	for(int i = 1; i <= n; i++)
		if ((a[i] & 31) == p){
			ans += max(0ll, (a[i] >> 5) + 1 - q);
		}
	cout<<ans<<endl;
}

void work2(){
	ll ans = 0;
	int p = b[1] & 31, pp = b[2] & 31;
	ll q = b[1] >> 5, qq = b[2] >> 5;
	for(int i = 1; i < n; i++)
		if ((a[i] & 31) == p && (a[i+1] & 31) == pp && (a[i] >= b[1]) && (a[i+1] >= b[2])){
			ans++;
		}
	cout<<ans<<endl;
}

#define _match(a,b) ((a) == (b))

void workkmp(int ls, ll * str, int lp, ll * pat){
//	cout<<ls<<' '<<lp<<endl;
//	cout<<str[0]<<' '<<str[1]<<' '<<str[2]<<endl;
//	cout<<pat[0]<<' '<<pat[1]<<endl;
//int pat_match(int ls,elem_t* str,int lp,elem_t* pat){
    int ret = 0;
    int fail[MAXN]={-1},i=0,j;
    for (j=1;j<lp;j++){
	for (i=fail[j-1];i>=0&&!_match(pat[i+1],pat[j]);i=fail[i]);
	fail[j]=(_match(pat[i+1],pat[j])?i+1:-1);
    }
    for (i=j=0;i<ls;i++) {
	if (_match(str[i],pat[j])) {
	    j++;
	    if (j == lp) {
		//	cout<<i<<' '<<j<<endl;
		//	cout<<str[i+1]<<' '<<pat[j]<<' '<<str[i-j]<<' '<<pat[-1]<<endl;
			if ((str[i+1] & 31) == (pat[j] & 31) && (str[i-j] & 31) == (pat[-1]& 31))
		//	cout<<i<<' '<<j<<endl;
	     	   ++ret;
	        j=fail[j-1]+1;         
	    }
	}
	else if (j)
	    j=fail[j-1]+1,i--;
    }
	cout<<ret<<endl;
   // return ret;
//}

}

int main(){
/*	int n = 5, m = 3;
	a[0] = 2, a[1] = 1, a[2] = 2, a[3] = 1, a[4] = 2, a[5] = 1;
	b[0] = 2, b[1] = 1, b[2] = 2, b[3] = 1;
	workkmp(n, a, m, b);
	return 0;*/
	cin>>n>>m;
	int cnt  = 0;
	for(int i = 1; i <= n; i++){
		int x;
		char ch;
		scanf("%d-%c", &x, &ch);
		ch -= 'a';
		if (cnt && ((a[cnt] & 31) == ch))
			a[cnt] += x << 5;
		else
			a[++cnt] = (x << 5) + ch;
	}
	n = cnt;
	cnt = 0;
	for(int i = 1; i <= m; i++){
		int x;
		char ch;
		scanf("%d-%c", &x, &ch);
		ch -= 'a';
		if (cnt && ((b[cnt] & 31) == ch))
			b[cnt] += x << 5;
		else
			b[++cnt] = (x << 5) + ch;
	}
	m = cnt;
/*	cout<<n<<endl;
	for(int i = 1; i<= n;i++)
		cout<<a[i]<<' '<<(a[i]>>5)<<' '<<(a[i] & 31)<<endl;
	cout<<m<<endl;
	for(int i = 1; i<= m;i++)
		cout<<b[i]<<' '<<(b[i]>>5)<<' '<<(b[i] & 31)<<endl;
*/	if (m == 1)
		work1();
	else
		if (m == 2)
			work2();
		else
			workkmp(n-2, a+2, m-2, b+2);
	return 0;
}