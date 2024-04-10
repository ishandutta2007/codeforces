# n = map(int,input().split())
n = int(input())
ans = "I hate"
for i in range(n-1):
	if i&1^1: ans += " that I love"
	else: ans += " that I hate"
ans += " it"
print(ans)