
S=raw_input()
T=str(eval(S))

R=""
for c in T:
	for a in range(int(c)+48):
		R+="+"
	R+=".>"

print R