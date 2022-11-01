#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#define pb push_back
#define mp make_pair
#define INF 9999999
#define LINF 9999999999999999
#define uint unsigned int
#define msn(a,v) memset(a,v,sizeof(a))
#define ms(a) msn(a,0)
#define NONE -1
#define ll long long
#define ull unsigned ll
#define uchar unsigned char
#define sint short int
#define usint unsigned sint
#define lb lower_bound
#define ub upper_bound
using namespace std;
#define MAXN 100100
#define MAXBLOCKCNT 400

int n , q;

//Block i : [ i*BLOCKSIZE , (i+1)*BLOCKSIZE )
deque<int>::iterator it;
int BLOCKSIZE , BLOCKCNT;
struct Block{
	deque<int> data;
	int cnt[MAXN];
	void init(){
		data.clear();
		ms(cnt);
	}
};
Block block[MAXBLOCKCNT];

void init(){
	BLOCKSIZE = (int)( pow( n , 0.634 ) );
	if( n/BLOCKSIZE == 0 ) BLOCKCNT = n/BLOCKSIZE;
	else BLOCKCNT = n/BLOCKSIZE + 1;
	//for( int i = 0 ; i < BLOCKCNT ; i++ )
	//	block[i].init();
	//cout << BLOCKSIZE << " " << BLOCKCNT << endl;
}

int main(){
//	freopen("455d.txt","r",stdin);
	
	scanf("%d",&n);
	init();
	for( int i = 0 ; i < n ; i++ ){
		int x;
		scanf("%d",&x);
		int id = i / BLOCKSIZE;
		block[id].data.push_back( x );
		block[id].cnt[x]++;
	}
	
	int ans = 0;
	scanf("%d",&q);
	for( int qi = 1 ; qi <= q ; qi++ ){
		int cmd,l,r,k;
		scanf("%d %d %d",&cmd,&l,&r);
		if(cmd == 2){
			scanf("%d",&k);
			k += ans;
			if( k > n ) k -= n ;
		}
		l += ans; l--; if( l >= n ) l -= n;
		r += ans; r--; if( r >= n ) r -= n;
		if( l > r ) swap( l , r );
		
		int id1 = l/BLOCKSIZE , id2 = r/BLOCKSIZE;
		int pos1 = l-id1*BLOCKSIZE , pos2 = r-id2*BLOCKSIZE;
		
		if( cmd == 1 ){
			if( id1 == id2 ){
				it = block[id1].data.begin() + pos2;
				int now = *it;
				block[id1].data.erase( it );
				block[id1].data.insert( block[id1].data.begin() + pos1 , now );
			}else{
				it = block[id2].data.begin() + pos2;
                int now = *it;
				block[id2].data.erase( it );
				block[id2].cnt[now]--;
				for( int i = id1 ; i < id2 ; i++ ){
					int now = block[i].data.back();
					block[i].data.pop_back();
					block[i].cnt[now]--;
					block[i+1].data.push_front( now );
					block[i+1].cnt[now]++;
				}
				block[id1].data.insert( block[id1].data.begin() + pos1 , now );
				block[id1].cnt[now]++;
			}
		}else{
			ans = 0;
			if( id1 == id2 ){
				//cout << "KIND1 ";
				for( it = block[id1].data.begin() + pos1 ; it <= block[id1].data.begin() + pos2 ; it++ )
					if( *it == k )
						ans++;
			}else{
				//cout << id1 << " " << pos1 << "   " << id2 << " " << pos2 << endl;
				for( it = block[id1].data.begin() + pos1 ; it < block[id1].data.end() ; it++ )
					if( *it == k )
						ans++;
				for( int i = id1 + 1 ; i < id2 ; i++ )
					ans += block[i].cnt[k];
				for( it = block[id2].data.begin() ; it <= block[id2].data.begin() + pos2 ; it++ )
					if( *it == k )
						ans++;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}