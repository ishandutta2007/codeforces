from collections import defaultdict
n = int(input());
a = [int(i) for i in input().split(" ")]
ans = 0
s = 0;
cnt = defaultdict(int);
for i in range(n):
	ans += a[i] * (i - cnt[a[i]] - cnt[a[i]-1] - cnt[a[i]+1]);
	cnt[a[i]]+=1
a = a[::-1]
cnt = defaultdict(int);
for i in range(n):
	ans -= a[i] * (i - cnt[a[i]] - cnt[a[i]-1] - cnt[a[i]+1]);
	cnt[a[i]]+=1
print(str(ans));