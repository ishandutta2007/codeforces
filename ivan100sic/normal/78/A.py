import re
def f(s):
	return len(re.findall('(a|e|i|o|u)', s))
if [5, 7, 5] == [f(input()), f(input()), f(input())]:
	print("YES")
else:
	print("NO")