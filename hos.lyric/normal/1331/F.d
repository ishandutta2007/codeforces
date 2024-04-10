import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.bitmanip, std.complex, std.container, std.math, std.mathspecial, std.numeric, std.regex, std.typecons;
import core.bitop;

class EOFException : Throwable { this() { super("EOF"); } }
string[] tokens;
string readToken() { for (; tokens.empty; ) { if (stdin.eof) { throw new EOFException; } tokens = readln.split; } auto token = tokens.front; tokens.popFront; return token; }
int readInt() { return readToken.to!int; }
long readLong() { return readToken.to!long; }
real readReal() { return readToken.to!real; }

bool chmin(T)(ref T t, in T f) { if (t > f) { t = f; return true; } else { return false; } }
bool chmax(T)(ref T t, in T f) { if (t < f) { t = f; return true; } else { return false; } }

int binarySearch(alias pred, T)(in T[] as) { int lo = -1, hi = cast(int)(as.length); for (; lo + 1 < hi; ) { const mid = (lo + hi) >> 1; (unaryFun!pred(as[mid]) ? hi : lo) = mid; } return hi; }
int lowerBound(T)(in T[] as, T val) { return as.binarySearch!(a => (a >= val)); }
int upperBound(T)(in T[] as, T val) { return as.binarySearch!(a => (a > val)); }


enum DATA = q"EOS
1	H	HYDROGEN
2	HE	HELIUM
3	LI	LITHIUM
4	BE	BERYLLIUM
5	B	BORON
6	C	CARBON
7	N	NITROGEN
8	O	OXYGEN
9	F	FLUORINE
10	NE	NEON
11	NA	SODIUM
12	MG	MAGNESIUM
13	AL	ALUMINUM
14	SI	SILICON
15	P	PHOSPHORUS
16	S	SULFUR
17	CL	CHLORINE
18	AR	ARGON
19	K	POTASSIUM
20	CA	CALCIUM
21	SC	SCANDIUM
22	TI	TITANIUM
23	V	VANADIUM
24	CR	CHROMIUM
25	MN	MANGANESE
26	FE	IRON
27	CO	COBALT
28	NI	NICKEL
29	CU	COPPER
30	ZN	ZINC
31	GA	GALLIUM
32	GE	GERMANIUM
33	AS	ARSENIC
34	SE	SELENIUM
35	BR	BROMINE
36	KR	KRYPTON
37	RB	RUBIDIUM
38	SR	STRONTIUM
39	Y	YTTRIUM
40	ZR	ZIRCONIUM
41	NB	NIOBIUM
42	MO	MOLYBDENUM
43	TC	TECHNETIUM
44	RU	RUTHENIUM
45	RH	RHODIUM
46	PD	PALLADIUM
47	AG	SILVER
48	CD	CADMIUM
49	IN	INDIUM
50	SN	TIN
51	SB	ANTIMONY
52	TE	TELLURIUM
53	I	IODINE
54	XE	XENON
55	CS	CESIUM
56	BA	BARIUM
57	LA	LANTHANUM
58	CE	CERIUM
59	PR	PRASEODYMIUM
60	ND	NEODYMIUM
61	PM	PROMETHIUM
62	SM	SAMARIUM
63	EU	EUROPIUM
64	GD	GADOLINIUM
65	TB	TERBIUM
66	DY	DYSPROSIUM
67	HO	HOLMIUM
68	ER	ERBIUM
69	TM	THULIUM
70	YB	YTTERBIUM
71	LU	LUTETIUM
72	HF	HAFNIUM
73	TA	TANTALUM
74	W	TUNGSTEN
75	RE	RHENIUM
76	OS	OSMIUM
77	IR	IRIDIUM
78	PT	PLATINUM
79	AU	GOLD
80	HG	MERCURY
81	TL	THALLIUM
82	PB	LEAD
83	BI	BISMUTH
84	PO	POLONIUM
85	AT	ASTATINE
86	RN	RADON
87	FR	FRANCIUM
88	RA	RADIUM
89	AC	ACTINIUM
90	TH	THORIUM
91	PA	PROTACTINIUM
92	U	URANIUM
93	NP	NEPTUNIUM
94	PU	PLUTONIUM
95	AM	AMERICIUM
96	CM	CURIUM
97	BK	BERKELIUM
98	CF	CALIFORNIUM
99	ES	EINSTEINIUM
100	FM	FERMIUM
101	MD	MENDELEVIUM
102	NO	NOBELIUM
103	LR	LAWRENCIUM
104	RF	RUTHERFORDIUM
105	DB	DUBNIUM
106	SG	SEABORGIUM
107	BH	BOHRIUM
108	HS	HASSIUM
109	MT	MEITNERIUM
110	DS	DARMSTADTIUM
111	RG	ROENTGENIUM
112	CN	COPERNICIUM
113	NH	NIHONIUM
114	FL	FLEROVIUM
115	MC	MOSCOVIUM
116	LV	LIVERMORIUM
117	TS	TENNESSINE
118	OG	OGANESSON
EOS";

void main() {
  bool[string] el;
  const tokens = DATA.split;
  for (int i = 1; i < tokens.length; i += 3) {
    el[tokens[i]] = true;
  }
  
  try {
    for (; ; ) {
      const S = readToken();
      auto L = cast(int)(S.length);
      
      auto dp = new bool[L + 1];
      dp[0] = true;
      foreach (i; 0 .. L) {
        if (dp[i]) {
          foreach (j; [i + 1, i + 2]) {
            if (j <= L) {
              if (S[i .. j] in el) {
                dp[j] = true;
              }
            }
          }
        }
      }
      writeln(dp[L] ? "YES" : "NO");
    }
  } catch (EOFException e) {
  }
}