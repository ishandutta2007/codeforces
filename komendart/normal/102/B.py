n = raw_input()
number = 0
while len(n) != 1:
    number += 1
    n = str(sum(int(i) for i in n))
print number