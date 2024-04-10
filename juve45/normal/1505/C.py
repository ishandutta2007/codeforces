

def sum(s):
	ss = 0
	for i in range(2, len(s)):
		if( (ord(s[i - 2]) + ord(s[i - 1]) - ord('A') - ord('A')) % 26 == ord(s[i]) - ord('A')):
			continue
		else:
			return 0	
	return 1

if sum(input()) == 1:
	print("YES")
else: 
	print("NO")