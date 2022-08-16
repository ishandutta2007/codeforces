import re
n, str = input(), raw_input()
wordList = re.sub("[^\w]", " ",  str).split()
def f(S):
	ret = 0
	for i in range(len(S)) : ret += (ord(S[i]) < 97)
	return ret
g = []
for x in wordList : g.append(f(x))
ans = reduce(lambda x, y : max(x, y), g, 0)
print ans