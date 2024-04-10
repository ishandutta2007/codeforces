for _ in range(int(input())):
	s = input()
	wyn = min(s.count('1'), s.count('0'))
	for cyk_dig in "01":
		cyk = s.count(cyk_dig)
		for c in s:
			cyk += (-1 if c == cyk_dig else 1)
			wyn = min(wyn, cyk)
	print(wyn)