import sys
input = sys.stdin.readline

def ProGamerMove():
	tmp = str(input())
	s = list(tmp[:len(tmp) - 1])
	n = len(s)

	rem = [0]
	stay = [s.count('0')]
	s.reverse()
	for c in s:
		rem.append(rem[-1] + int(c == '1'))
		stay.append(stay[-1] - int(c == '0'))
	s.reverse()
	rem.reverse()
	stay.reverse()

	rd, rs = 0, 0
	def f(i): return max(rem[i] + rd, stay[i] - rs)

	b, res = 0, n
	for c in s:
		while b < n and f(b) >= f(b + 1): b += 1
		res = min(res, f(b))
		rd += c == '1'
		rs += c == '0'

	while b < n and f(b) >= f(b + 1): b += 1
	res = min(res, f(b))

	print(res)

n = 0
n = int(input())
for _ in range(0, n): ProGamerMove()