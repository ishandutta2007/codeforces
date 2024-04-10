import string

s =raw_input()
t =raw_input()

s = s.replace('a', '0')
s = s.replace('e', '0')
s = s.replace('i', '0')
s = s.replace('o', '0')
s = s.replace('u', '0')

t = t.replace('a', '0')
t = t.replace('e', '0')
t = t.replace('i', '0')
t = t.replace('o', '0')
t = t.replace('u', '0')

for i in string.ascii_lowercase:
	s = s.replace(i, '1')
	t = t.replace(i, '1')

if s == t:
	print "Yes"
else:
	print "No"