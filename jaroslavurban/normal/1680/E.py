import sys
input = sys.stdin.readline

def ProGamerMove():
	n = int(input())
	s = []
	for t in range(0, 2):
		cs = list(input())
		s.append(cs[:n])
	i = 0
	while s[0][i] != '*' and s[1][i] != '*': i += 1
	while s[0][n - 1] == '.' and s[1][n - 1] == '.': n -= 1
	dp = 4 * [1e9]
	dp[1] = int(s[0][i] == '*')
	dp[2] = int(s[1][i] == '*')
	if s[0][i] == '*' and s[1][i] == '*': dp[3] = 0
	i += 1
	while i < n:
#		print(dp)
		ndp = 4 * [1e9]
		if s[0][i] == '*' and s[1][i] == '*':
			ndp[3] = min(dp[3] + 2, dp[1] + 1, dp[2] + 1)
			ndp[2] = min(dp[3] + 3, dp[1] + 2, dp[2] + 2)
			ndp[1] = min(dp[3] + 3, dp[1] + 2, dp[2] + 2)
		if s[0][i] == '.' and s[1][i] == '*':
			ndp[3] = min(dp[3] + 2, dp[1] + 2, dp[2] + 1)
			ndp[2] = min(dp[3] + 3, dp[1] + 2, dp[2] + 2)
			ndp[1] = min(dp[3] + 2, dp[1] + 1, dp[2] + 2)
		if s[0][i] == '*' and s[1][i] == '.':
			ndp[3] = min(dp[3] + 2, dp[1] + 2, dp[2] + 1)
			ndp[2] = min(dp[3] + 2, dp[1] + 2, dp[2] + 1)
			ndp[1] = min(dp[3] + 3, dp[1] + 2, dp[2] + 2)
		if s[0][i] == '.' and s[1][i] == '.':
			ndp[3] = dp[3] + 2
			ndp[2] = min(dp[3] + 2, dp[1] + 2, dp[2] + 1)
			ndp[1] = min(dp[3] + 2, dp[1] + 1, dp[2] + 2)
		dp = ndp
		i += 1
#	print(dp)
	print(min(dp[3] + 1, dp[1], dp[2]))

n = 1
n = int(input())
for _ in range(0, n): ProGamerMove()