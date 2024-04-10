#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

inline int read(){
    int a = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c)){
        if(c == '-')
            f = 1;
        c = getchar();
    }
    while(isdigit(c)){
        a = a * 10 + c - 48;
        c = getchar();
    }
    return f ? -a : a;
}

const int MAXN = 1e5 + 7;
stack < long long > dp1 , dp2;
struct stg{
    int a , b;
    bool operator <(const stg t)const{
        return a < t.a;
    }
}now[MAXN];
int mice[MAXN] , hole[MAXN][2] , times[MAXN][2] , dp[MAXN * 3][2];
int N , M , cnt;
long long sum , tag1 , tag2 , dp0;

int main(){
    N = read();
    M = read();
    for(int i = 1 ; i <= N ; ++i)
        mice[i] = read();
    sort(mice + 1 , mice + N + 1);
    for(int i = 1 ; i <= M ; ++i){
        now[i].a = read();
        now[i].b = read();
        sum += now[i].b;
    }
    sort(now + 1 , now + M + 1);
    for(int i = 1 ; i <= M ; ++i){
        hole[i][0] = now[i].a;
        hole[i][1] = now[i].b;
    }
    if(sum < N){
        puts("-1");
        return 0;
    }
    	int p1 = 1 , p2 = 1;
	while(p1 <= N || p2 <= M)
		if(p1 <= N && (p2 > M || hole[p2][0] > mice[p1])){
			++p1;
			if(!dp1.empty()){
				int t = dp1.top();
				dp1.pop();
				if(++times[t][0] != hole[t][1])
					dp1.push(t);
			}
			else
				++cnt;
		}
		else
			if(cnt < hole[p2][1]){
				times[p2][0] = cnt;
				cnt = 0;
				dp1.push(p2++);
			}
			else{
				times[p2][0] = hole[p2][1];
				cnt -= hole[p2++][1];
			}
	p1 = N;
	p2 = M;
	cnt = 0;
	dp1 = dp2;
	while(p1 || p2)
		if(p1 && (!p2 || hole[p2][0] < mice[p1])){
			--p1;
			if(!dp1.empty()){
				int t = dp1.top();
				dp1.pop();
				if(++times[t][1] != hole[t][1])
					dp1.push(t);
			}
			else
				++cnt;
		}
		else
			if(cnt < hole[p2][1]){
				times[p2][1] = cnt;
				cnt = 0;
				dp1.push(p2--);
			}
			else{
				times[p2][1] = hole[p2][1];
				cnt -= hole[p2--][1];
			}
	p1 = 1;
	p2 = 1;
	cnt = 0;
	while(p1 <= N || p2 <= M)
		if(p1 <= N && (p2 > M || hole[p2][0] > mice[p1]))
			dp[++cnt][0] = mice[p1++];
		else{
			for(int i = min(times[p2][0] + times[p2][1] , hole[p2][1]) ; i ; --i){
				dp[++cnt][0] = hole[p2][0];
				dp[cnt][1] = 1;
				--times[p2][0];
			}
			++p2;
		}
    dp1 = dp2;
    for(int i = 1 ; i <= cnt ; ++i)
        if(!dp[i][1]){
            dp1.push(dp0 - tag1);
            tag1 -= dp[i][0];
            tag2 += dp[i][0];
            if(!dp2.empty()){
                dp0 = dp2.top() + tag2;
                dp2.pop();
            }
            else
                dp0 = 1e15;
        }
        else{
            dp2.push(dp0 - tag2);
            tag1 += dp[i][0];
            tag2 -= dp[i][0];
            if(!dp1.empty()){
                dp0 = min(dp0 , dp1.top() + tag1);
                dp1.pop();
            }
        }
    cout << dp0;
    return 0;
}