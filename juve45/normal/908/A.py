x = input()
ans = 0
for ch in x:
	if ch in "aeiou13579": 
		ans += 1
print(ans)