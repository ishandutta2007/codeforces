s = raw_input()
best = -1
for i in range(len(s) + 1):
	for j in range(i, len(s) + 1):
		s1 = s[:i]
		s2 = s[i:j]
		s3 = s[j:]
		if s1 == "" or (s1[0] == "0" and s1 != "0") or int(s1) > 1000000:
			continue
		if s2 == "" or (s2[0] == "0" and s2 != "0") or int(s2) > 1000000:
			continue
		if s3 == "" or (s3[0] == "0" and s3 != "0") or int(s3) > 1000000:
			continue
		best = max(best, int(s1) + int(s2) + int(s3))
		
print best