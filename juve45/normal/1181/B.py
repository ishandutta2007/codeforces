n = int(raw_input())
s = raw_input()

mid = n / 2 + 1;
while mid < n and s[mid] == '0':
	mid+=1

r1 = s[:mid]
r2 = s[mid:]

ans = int(s)

if len(r2) > 0:
	ans = min(ans, int(r1) + int(r2))
# print r1, r2


mid = n / 2;
while mid > 0 and s[mid] == '0':
	mid -= 1

# print mid, s[mid]

r1 = s[:mid]
r2 = s[mid:]

# print r1, r2

if len(r1) > 0:
	ans = min(ans, int(r1) + int(r2))

print ans