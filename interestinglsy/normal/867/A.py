input()
s = input().strip()
last = s[0]
fts = stf = 0
for c in s:
	if c != last:
		if c == 'S': fts += 1
		else: stf += 1
	last = c
print( 'Yes' if stf>fts else 'No' )