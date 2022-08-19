s = raw_input()
for i in xrange(len(s) - 1):
	u, v = s[i], s[i + 1]
	if (not u in "aeioun") and (not v in "aeiou"):
		print "NO"
		exit(0)
if not s[-1] in "aeioun":
	print "NO"
	exit(0)
print "YES"